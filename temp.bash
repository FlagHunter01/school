### Topologie du Projet Réseau
3 routeurs Cisco 1941
3 switchs Cisco 2960-24TT
3 PC


## Configuration du Routeur R1

Router>en
Router#conf t
Router(config)#hostname R1

# On désactive la résolution de nom de domaine (DNS) pour éviter des retards inutiles lors de la saisie de commandes.
R1(config)#no ip domain lookup


# On attribue l'adresse IP 172.16.1.252 avec un masque de sous-réseau 255.255.255.0 à cette interface.
# On configure l'adresse IP virtuelle 172.16.1.254 pour le protocole HSRP (Hot Standby Router Protocol) avec une priorité par défaut.
R1(config)#interface gigabitEthernet 0/0
R1(config-if)#no shutdown
R1(config-if)#ip address 172.16.1.252 255.255.255.0
R1(config-if)#standby 10 ip 172.16.1.254
R1(config-if)#exit


# On attribue la priorité 105 au groupe HSRP (par rapport à une priorité par défaut de 100) pour que ce routeur devienne le routeur actif en cas d'égalité.
# On configure la préemption, ce qui permettra au routeur avec la plus haute priorité de reprendre le rôle de routeur actif lorsqu'il devient disponible.
R1(config)#exit
R1#sh standby brief
R1#conf t
R1(config)#interface gigabitEthernet 0/0
R1(config-if)#standby 10 priority 105
R1(config-if)#standby 10 preempt 


# On attribue l'adresse IP 192.168.1.254 avec un masque de sous-réseau 255.255.255.0 à cette interface. Cette interface sera utilisée pour la connectivité "extérieure".
# On spécifie que l'interface GigabitEthernet 0/0 est une interface "intérieure" pour la traduction d'adresses réseau (NAT).
R1#conf t
R1(config)#interface gigabitEthernet 0/1
R1(config-if)#no sh
R1(config-if)#ip address 192.168.1.254 255.255.255.0
R1(config-if)#ip nat outside
R1(config-if)#exit
R1(config)#interface gigabitEthernet 0/0
R1(config-if)#ip nat inside
R1(config-if)#exit

# On crée une liste d'accès étendue numéro 100.
# On configure la traduction d'adresses réseau (NAT) en utilisant l'interface GigabitEthernet 0/1 comme interface "extérieure" avec un pool d'adresses IP internes défini par la liste d'accès 100.
# On supprime la liste d'accès 100 (pour la modifier).
# On configure une règle dans la liste d'accès 100 pour interdire le trafic provenant du réseau 172.16.1.0/24 à destination du réseau 10.1.1.0/24.
# On ajoute une règle dans la liste d'accès 100 pour autoriser tout autre trafic provenant du réseau 172.16.1.0/24.
R1(config)#access-list 100 permit ip 172.16.1.0 0.0.0.255 any
R1(config)#ip nat inside source list 100 interface gigabitEthernet 0/1 overload 
R1(config)#no access-list 100
R1(config)#access-list 100 deny ip 172.16.1.0 0.0.0.255 10.1.1.0 0.0.0.255
R1(config)#access-list 100 permit ip 172.16.1.0 0.0.0.255 any
R1(config)#license boot module c1900 technology-package securityk9 
R1(config)#exit

# On configure une politique de sécurité pour le protocole ISAKMP (Internet Security Association and Key Management Protocol) avec un identifiant de 10.
# On définit l'algorithme de chiffrement AES, l'algorithme de hachage SHA, la durée de vie de la clé à 14400 secondes, l'authentification par pré-partage et le groupe de clés 5.
# On définit une clé pré-partagée "Cisco123" pour l'établissement de la connexion VPN avec n'importe quelle adresse IP distante (0.0.0.0).
# On configure un jeu de transformation IPsec nommé "MYTS" utilisant les algorithmes AES pour le chiffrement et SHA-HMAC pour le hachage.
# On crée une liste d'accès étendue nommée "TI" pour spécifier le trafic qui sera crypté via le tunnel VPN (dans cet exemple, le trafic du réseau local 172.16.1.0/24 à destination du réseau 10.0.0.0/8).
# On configure une carte crypto nommée "MYMAP" avec un identifiant de 10 pour lier la politique ISAKMP, le pair distant (8.8.8.8) et le jeu de transformation IPsec "MYTS".
# On associe la carte crypto "MYMAP" à l'interface GigabitEthernet 0/1, indiquant que le trafic sortant de cette interface sera crypté en utilisant la configuration définie dans la carte crypto "MYMAP".
R1#copy running-config startup-config 
R1#Reload
R1>en
R1#conf
R1(config)#crypto isakmp policy 10
R1(config-isakmp)#encryption aes
R1(config-isakmp)#hash sha
R1(config-isakmp)#lifetime 14400
R1(config-isakmp)#authentication pre-share
R1(config-isakmp)#group 5
R1(config-isakmp)#exit
R1(config)#crypto isakmp key Cisco123 address 0.0.0.0
R1(config)#crypto ipsec transform-set MYTS esp-aes esp-sha-hmac 
R1(config)#ip access-list extended TI
R1(config-ext-nacl)#permit ip 172.16.1.0 0.0.0.255 10.0.0.0 0.255.255.255
R1(config-ext-nacl)#exit
R1(config)#crypto map MYMAP 10 ipsec-isakmp 
R1(config-crypto-map)#set peer 8.8.8.8
R1(config-crypto-map)#match address TI
R1(config-crypto-map)#set transform-set MYTS
R1(config-crypto-map)#exit
R1(config)#interface gigabitEthernet 0/1
R1(config-if)#crypto map MYMAP
R1(config-if)#exit
R1(config)#exit
R1#sh crypto ipsec sa



## Configuration du Routeur R2
Router>en
Router#conf t
Router(config)#hostname R2
R2(config)#no ip domain lookup
R2(config)#interface gigabitEthernet 0/0
R2(config-if)#no shutdown
R2(config-if)#ip address 172.16.1.253 255.255.255.0
R2(config-if)#standby 10 ip 172.16.1.254
R2(config-if)#exit
R2(config)#exit
R2#sh standby brief
R2#conf t
R2(config)#interface gigabitEthernet 0/0
R2(config-if)#standby 10 priority 105
R2(config-if)#standby 10 preempt


## Configuration des PC
PC0
Default Gateway --> 172.16.1.254
IPv4 Address --> 172.16.1.1
Subnet Mask --> 255.255.255.0
Ping vers 172.16.1.254 (OK)

PC1
Default Gateway --> 172.16.1.254
IPv4 Address --> 172.16.1.2
Subnet Mask --> 255.255.255.0
Ping vers 172.16.1.254 (OK)
