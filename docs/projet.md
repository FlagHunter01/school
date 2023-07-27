---
title: PROJET
description: C'EST NOTRE PROJET!
---

!!! tip "[DL MON DELIRE ICI](conf_base.pkt)"

## Site local

### R1

```sh
en
conf t

# Conf usuele
hostname R1
no ip domain lookup
enable secret OATE
banner motd #R1#

# SSH
ip domain name cisco.com
crypto key generate rsa general-keys modulus 2048
username Admin secret cisco
ip ssh version 2
line vty 0 15
transport input ssh
exit

# Interface LAN
int GigabitEthernet0/0
description LAN
ip address 172.16.1.252 255.255.255.0
ip nat inside
no shutdown
exit

# Interface WAN
int GigabitEthernet0/1
description WAN
ip address 80.0.0.1 255.255.255.0
ip nat outside
no shutdown
exit

# GLBP
interface GigabitEthernet0/0.99
description LAN
encapsulation dot1Q 99
ip address 172.16.1.252 255.255.255.0
ip nat inside
ip virtual-reassembly in
glbp 1 ip 172.16.1.254
glbp 1 priority 140
glbp 1 preempt
exit

# VPN
access-list 100 deny ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
access-list 100 permit ip 172.16.1.0 0.0.0.255 any
license boot module c1900 technology-package securityk9 

crypto isakmp policy 10
encryption aes
hash sha
lifetime 14400
authentication pre-share
group 5
exit
crypto isakmp key cisco1 address 80.0.0.3
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac 
ip access-list extended VPNLIST
permit ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
exit
crypto map MAINMAP 10 ipsec-isakmp 
set peer 80.0.0.3
match address VPNLIST
set transform-set MYTS
exit
int GigabitEthernet0/1
crypto map MAINMAP
exit
exit
wr
```

### R2

```sh
en
conf t

# Conf usuele
hostname R2
no ip domain lookup
enable secret OATE
banner motd #R2#

# SSH
ip domain name cisco.com
crypto key generate rsa general-keys modulus 2048
username Admin secret cisco
ip ssh version 2
line vty 0 15
transport input ssh
exit

# Interface LAN
int GigabitEthernet0/0
description LAN
ip address 172.16.1.253 255.255.255.0
ip nat inside
no shutdown
exit

# Interface WAN
int GigabitEthernet0/1
description WAN
ip address 80.0.0.2 255.255.255.0
ip nat outside
no shutdown
exit

#GLBP
interface GigabitEthernet0/0.99
description LAN
encapsulation dot1Q 99
ip address 172.16.1.253 255.255.255.0
ip nat inside
ip virtual-reassembly in
glbp 1 ip 172.16.1.254
exit 

# VPN
access-list 100 deny ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
access-list 100 permit ip 172.16.1.0 0.0.0.255 any
license boot module c1900 technology-package securityk9 

crypto isakmp policy 10
encryption aes
hash sha
lifetime 14400
authentication pre-share
group 5
exit
crypto isakmp key cisco2 address 80.0.0.3
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac 
ip access-list extended VPNLIST
permit ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
exit
crypto map MAINMAP 10 ipsec-isakmp 
set peer 80.0.0.3
match address VPNLIST
set transform-set MYTS
exit
int GigabitEthernet0/1
crypto map MAINMAP
exit
exit
wr
```

### S1

!!! warning "DHCP disfonctionnel"

```sh
enable
config ter

hostname S1
banner motd #S1#

vlan 99
name MANAGEMENT
exit

int vlan 99
ip address 172.16.1.251 255.255.255.0
no shutdown
exit

interface range FastEthernet 1/0/1 - 48
switchport mode access
switchport access vlan 99
no shutdown
exit

ip dhcp excluded-address 172.16.1.201 172.16.1.255
ip dhcp pool local
network 172.16.1.0 255.255.255.0
default-router 172.16.1.254
exit

ip domain name ccna.com
username Admin secret cisco

line vty 0 15
login local
transport input ssh 
exit

exit
wr
```

## Site distant

### RA

!!! failure "Pas de DHCP pour l'instant"

```sh
en
conf t

# Conf usuele
hostname RA
no ip domain lookup
enable secret OATE
banner motd #RA#

# SSH
ip domain name cisco.com
crypto key generate rsa general-keys modulus 2048
username Admin secret cisco
ip ssh version 2
line vty 0 15
transport input ssh
exit

# Interface LAN
int GigabitEthernet0/0
description LAN
ip address 10.10.10.254 255.255.255.0
ip nat inside
no shutdown
exit

# Interface WAN
int GigabitEthernet0/1
description WAN
ip address 80.0.0.3 255.255.255.0
ip nat outside
no shutdown
exit

# GLBP
interface GigabitEthernet0/1.99
description LAN
encapsulation dot1Q 99
ip address 10.10.10.254 255.255.255.0
ip nat inside
ip virtual-reassembly in
exit

# VPN
access-list 100 deny ip 10.10.10.0 0.0.0.255 172.16.1.0 0.0.0.255
access-list 100 permit ip 10.10.10.0 0.0.0.255 any
license boot module c1900 technology-package securityk9 

# VPN principal
crypto isakmp policy 10
encryption aes
hash sha
lifetime 14400
authentication pre-share
group 5
exit
crypto isakmp key cisco1 address 80.0.0.1
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac 
ip access-list extended VPNLIST
permit ip 10.10.10.0 0.0.0.255 172.16.1.0 0.0.0.255
exit
crypto map MAINMAP 10 ipsec-isakmp 
set peer 80.0.0.1
match address VPNLIST
set transform-set MYTS

# VPN secondaire
crypto isakmp policy 9
encryption aes
hash sha
lifetime 14400
authentication pre-share
group 5
exit
crypto isakmp key cisco2 address 80.0.0.2
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac 
ip access-list extended VPNLIST
permit ip 10.10.10.0 0.0.0.255 172.16.1.0 0.0.0.255
exit
crypto map MAINMAP 10 ipsec-isakmp 
set peer 80.0.0.2
match address VPNLIST
set transform-set MYTS
exit
int GigabitEthernet0/1
crypto map MAINMAP
exit
exit
wr
```

### SA

```sh
en
conf t

# Conf usuele
hostname SA
no ip domain lookup
enable secret OATE
banner motd #SA#


vlan 99
name MANAGEMENT
exit

int vlan 99
ip address 10.10.10.253 255.255.255.0

# range à retravailler 
interface range FastEthernet 0/1 - 24 
switchport mode access
switchport access vlan 99
no shutdown
exit 

ip dhcp excluded-address 10.10.10.201 10.10.10.255
ip dhcp pool local
network 10.10.10.0 255.255.255.0
default-router 10.10.10.254
exit
exit 

wr
```

## PRTG

```
snmp-server community prtg ro
```
