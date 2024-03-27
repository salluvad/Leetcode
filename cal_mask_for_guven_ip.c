
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16];
    printf("Enter an IPv4 address: ");
    scanf("%15s", ip);
    
    // Tokenize the input IP address and get the first octet
    int first_octet = atoi(strtok(ip, "."));
    
    // Determine the class of the IP address and assign the default subnet mask
    char subnet_mask[16];
    if (first_octet >= 1 && first_octet <= 126) {
        // Class A
        strcpy(subnet_mask, "255.0.0.0");
    } else if (first_octet >= 128 && first_octet <= 191) {
        // Class B
        strcpy(subnet_mask, "255.255.0.0");
    } else if (first_octet >= 192 && first_octet <= 223) {
        // Class C
        strcpy(subnet_mask, "255.255.255.0");
    } else {
        // IP address does not belong to class A, B, or C
        printf("The given IP address does not belong to class A, B, or C.\n");
        return 1;
    }
    
    // Output the default subnet mask
    printf("Default subnet mask for %d.x.x.x is %s\n", first_octet, subnet_mask);
    
    return 0;
}
