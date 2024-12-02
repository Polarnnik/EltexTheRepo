#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>

#define IPV4_BITS 32

u_int32_t ipToInt(const char* ip) {
    struct sockaddr_in soketA;
    inet_pton(AF_INET, ip, &(soketA.sin_addr));
    return soketA.sin_addr.s_addr;
}

int isInSubnet(uint32_t ip, uint32_t network, uint32_t mask)  {
    return (ip & mask) == (network & mask);
}

uint32_t generateRandomIP() {
    return (rand() % 256) << 24 | (rand() % 256) << 16 | (rand() % 256) << 8 | (rand() % 256);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Использование: %s <ip> <маска> <кол-во пакетов>\n", argv[0]);
        return 1;
    }


    uint32_t gatewayIp = ipToInt(argv[1]);
    uint32_t subnetMask = ipToInt(argv[2]);
    int numPackets = atoi(argv[3]);

    if (numPackets <= 0) {
        printf("Кол-во пакетов не может быть меньше нуля\n");
        return 1;
    }

    int ownSubnetCount = 0;
    int otherSubnetCount = 0;

    srand(time(NULL));

    for (int i = 0; i < numPackets; i++) {
        uint32_t destIp = generateRandomIP();

        struct in_addr destAddr;
        destAddr.s_addr = destIp;
        printf("Пакет %d: Назначение IP = %s\n", i + 1, inet_ntoa(destAddr));

        if (isInSubnet(destIp, gatewayIp, subnetMask)) {
            ownSubnetCount++;
        } else {
            otherSubnetCount++;
        }
    }

    printf("\nСтатистика:\n");
    printf("Пакетов в одной подсети: %d (%.2f%%)\n", ownSubnetCount,
           (float)ownSubnetCount / numPackets * 100);
    printf("Пакеты в других подсетях: %d (%.2f%%)\n", otherSubnetCount,
           (float)otherSubnetCount / numPackets * 100);

    return 0;
}