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

## Configs finales brutes

```title="R1"
!
version 15.4
service timestamps debug datetime msec
service timestamps log datetime msec
no service password-encryption
!
hostname R1
!
boot-start-marker
boot-end-marker
!
!
enable secret 5 $1$UoNG$YRQ69hrATcNPgFJUAhEVD1
!
no aaa new-model
memory-size iomem 10
!
!
!
!
!
!
!
!
!
!
!
!
!
!


!
!
!
!
no ip domain lookup
ip cef
no ipv6 cef
!
multilink bundle-name authenticated
!
!
cts logging verbose
!
!
license udi pid CISCO1941/K9 sn FCZ2036407D
license boot module c1900 technology-package securityk9
license boot module c1900 technology-package datak9
!
!
username Admin secret 5 $1$3BZ3$S0f7V4.bk96xcckVWLO7F/
!
redundancy
!
!
!
!
!
ip ssh version 2
!
!
crypto isakmp policy 10
 encr aes
 authentication pre-share
 group 5
 lifetime 14400
crypto isakmp key cisco1 address 80.0.0.3
!
!
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac
 mode tunnel
!
!
!
crypto map MAINMAP 10 ipsec-isakmp
 set peer 80.0.0.3
 set transform-set MYTS
 match address VPNLIST
!
!
!
!
!
interface Loopback0
 no ip address
 shutdown
!
interface Embedded-Service-Engine0/0
 no ip address
 shutdown
!
interface GigabitEthernet0/0
 description LAN
 no ip address
 duplex auto
 speed auto
!
interface GigabitEthernet0/0.99
 description LAN
 encapsulation dot1Q 99
 ip address 172.16.1.252 255.255.255.0
 ip nat inside
 ip virtual-reassembly in
 glbp 1 ip 172.16.1.254
 glbp 1 priority 140
 glbp 1 preempt
!
interface GigabitEthernet0/1
 description WAN
 ip address 80.0.0.1 255.255.255.0
 ip nat outside
 ip virtual-reassembly in
 duplex auto
 speed auto
 crypto map MAINMAP
!
interface Serial0/1/0
 no ip address
 clock rate 2000000
!
interface Serial0/1/1
 ip address 10.4.5.1 255.255.255.0
 clock rate 2000000
!
interface GigabitEthernet0/0/0
 no ip address
!
interface GigabitEthernet0/0/1
 no ip address
!
interface GigabitEthernet0/0/2
 no ip address
!
interface GigabitEthernet0/0/3
 no ip address
!
interface Vlan1
 no ip address
!
ip forward-protocol nd
!
no ip http server
no ip http secure-server
!
ip nat inside source list 100 interface GigabitEthernet0/1 overload
ip route 10.10.10.0 255.255.255.0 80.0.0.3
!
ip access-list extended VPNLIST
 permit ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
!
!
!
access-list 100 deny   ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
access-list 100 permit ip 172.16.1.0 0.0.0.255 any
!
control-plane
!
!
banner motd ^CR1^C
!
line con 0
line aux 0
line 2
 no activation-character
 no exec
 transport preferred none
 transport output lat pad telnet rlogin lapb-ta mop udptn v120 ssh
 stopbits 1
line vty 0 4
 login
 transport input ssh
line vty 5 15
 login
 transport input ssh
!
scheduler allocate 20000 1000
!
end
```

```title="R2"
!
version 15.4
service timestamps debug datetime msec
service timestamps log datetime msec
no service password-encryption
!
hostname R2
!
boot-start-marker
boot-end-marker
!
!
enable secret 5 $1$xaoj$i/BIUHtCRUPE.aAsKzv2G1
!
no aaa new-model
!
!
!
!
!
!
!
!
!
!
!
!
!
!


!
!
!
!
no ip domain lookup
ip cef
no ipv6 cef
!
multilink bundle-name authenticated
!
!
cts logging verbose
!
!
license udi pid CISCO1941/K9 sn FCZ152990LJ
license accept end user agreement
license boot module c1900 technology-package securityk9
license boot module c1900 technology-package datak9
!
!
username Admin secret 5 $1$TNVT$9fEdZcklhJr1syABxWRRZ/
!
redundancy
!
!
!
!
!
ip ssh version 2
!
!
crypto isakmp policy 10
 encr aes
 authentication pre-share
 group 5
 lifetime 14400
crypto isakmp key cisco2 address 80.0.0.3
!
!
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac
 mode tunnel
!
!
!
crypto map MAINMAP 10 ipsec-isakmp
 set peer 80.0.0.3
 set transform-set MYTS
 match address VPNLIST
!
!
!
!
!
interface Embedded-Service-Engine0/0
 no ip address
 shutdown
!
interface GigabitEthernet0/0
 description LAN
 no ip address
 duplex auto
 speed auto
!
interface GigabitEthernet0/0.99
 description LAN
 encapsulation dot1Q 99
 ip address 172.16.1.253 255.255.255.0
 ip nat inside
 ip virtual-reassembly in
 glbp 1 ip 172.16.1.254
!
interface GigabitEthernet0/1
 description WAN
 ip address 80.0.0.2 255.255.255.0
 ip nat outside
 ip virtual-reassembly in
 duplex auto
 speed auto
 crypto map MAINMAP
!
interface Serial0/1/0
 no ip address
 shutdown
 clock rate 2000000
!
interface Serial0/1/1
 no ip address
 shutdown
 clock rate 2000000
!
interface GigabitEthernet0/0/0
 description LAN
 no ip address
!
interface GigabitEthernet0/0/1
 description WAN
 no ip address
!
interface GigabitEthernet0/0/2
 no ip address
!
interface GigabitEthernet0/0/3
 no ip address
!
interface Vlan1
 no ip address
!
ip forward-protocol nd
!
no ip http server
no ip http secure-server
!
ip nat inside source list 100 interface GigabitEthernet0/1 overload
ip route 10.10.10.0 255.255.255.0 80.0.0.3
!
ip access-list extended VPNLIST
 permit ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
!
!
!
access-list 100 deny   ip 172.16.1.0 0.0.0.255 10.10.10.0 0.0.0.255
access-list 100 permit ip 172.16.1.0 0.0.0.255 any
!
control-plane
!
!
banner motd ^CR2^C
!
line con 0
line aux 0
line 2
 no activation-character
 no exec
 transport preferred none
 transport output lat pad telnet rlogin lapb-ta mop udptn v120 ssh
 stopbits 1
line vty 0 4
 login
 transport input ssh
line vty 5 15
 login
 transport input ssh
!
scheduler allocate 20000 1000
!
end
```

```title="S1"
!
version 12.2
no service pad
service timestamps debug uptime
service timestamps log uptime
no service password-encryption
!
hostname S1
!
enable secret 5 $1$1dFF$OLvsDsulJVeOSYEiDGBZv.
!
username Admin secret 5 $1$2LDx$/M8VWJjDY877ofoivOEOV/
no aaa new-model
switch 1 provision ws-c3750-48p
ip subnet-zero
ip domain-name cisco.com
ip dhcp excluded-address 172.16.1.201 172.16.1.255
!
ip dhcp pool local
   network 172.16.1.0 255.255.255.0
   default-router 172.16.1.254
!
ip ssh version 2
!
!
!
!
!
no file verify auto
spanning-tree mode pvst
spanning-tree extend system-id
!
vlan internal allocation policy ascending
!
!
interface FastEthernet1/0/1
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode trunk
!
interface FastEthernet1/0/2
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode trunk
!
interface FastEthernet1/0/3
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode access
!
interface FastEthernet1/0/4
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode access
!
interface FastEthernet1/0/5
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/6
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/7
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/8
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/9
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/10
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/11
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/12
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/13
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/14
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/15
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/16
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/17
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/18
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/19
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/20
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/21
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/22
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/23
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/24
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/25
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/26
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/27
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/28
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/29
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/30
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/31
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/32
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/33
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/34
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/35
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/36
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/37
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/38
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/39
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/40
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/41
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/42
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/43
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/44
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/45
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/46
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/47
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/48
 switchport access vlan 99
 switchport mode access
!
interface GigabitEthernet1/0/1
!
interface GigabitEthernet1/0/2
!
interface GigabitEthernet1/0/3
!
interface GigabitEthernet1/0/4
!
interface Vlan1
 no ip address
 shutdown
!
interface Vlan99
 ip address 172.16.1.251 255.255.255.0
!
ip default-gateway 172.16.1.254
ip classless
ip http server
ip http secure-server
!
!
!
control-plane
!
banner motd ^CS1^C
!
line con 0
line vty 0 4
 login local
 transport input ssh
line vty 5 15
 login local
 transport input ssh
!
!
end
```

```title="SA"
!
version 12.2
no service pad
service timestamps debug uptime
service timestamps log uptime
no service password-encryption
!
hostname S1
!
enable secret 5 $1$1dFF$OLvsDsulJVeOSYEiDGBZv.
!
username Admin secret 5 $1$2LDx$/M8VWJjDY877ofoivOEOV/
no aaa new-model
switch 1 provision ws-c3750-48p
ip subnet-zero
ip domain-name cisco.com
ip dhcp excluded-address 172.16.1.201 172.16.1.255
!
ip dhcp pool local
   network 172.16.1.0 255.255.255.0
   default-router 172.16.1.254
!
ip ssh version 2
!
!
!
!
!
no file verify auto
spanning-tree mode pvst
spanning-tree extend system-id
!
vlan internal allocation policy ascending
!
!
interface FastEthernet1/0/1
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode trunk
!
interface FastEthernet1/0/2
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode trunk
!
interface FastEthernet1/0/3
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode access
!
interface FastEthernet1/0/4
 switchport access vlan 99
 switchport trunk encapsulation dot1q
 switchport mode access
!
interface FastEthernet1/0/5
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/6
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/7
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/8
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/9
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/10
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/11
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/12
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/13
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/14
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/15
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/16
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/17
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/18
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/19
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/20
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/21
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/22
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/23
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/24
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/25
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/26
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/27
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/28
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/29
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/30
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/31
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/32
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/33
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/34
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/35
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/36
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/37
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/38
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/39
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/40
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/41
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/42
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/43
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/44
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/45
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/46
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/47
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/48
 switchport access vlan 99
 switchport mode access
!
interface GigabitEthernet1/0/1
!
interface GigabitEthernet1/0/2
!
interface GigabitEthernet1/0/3
!
interface GigabitEthernet1/0/4
!
interface Vlan1
 no ip address
 shutdown
!
interface Vlan99
 ip address 172.16.1.251 255.255.255.0
!
ip default-gateway 172.16.1.254
ip classless
ip http server
ip http secure-server
!
!
!
control-plane
!
banner motd ^CS1^C
!
line con 0
line vty 0 4
 login local
 transport input ssh
line vty 5 15
 login local
 transport input ssh
!
!
end
```

```title="RA"
!
! Last configuration change at 09:48:42 UTC Fri Jul 28 2023
!
version 15.4
service timestamps debug datetime msec
service timestamps log datetime msec
no service password-encryption
!
hostname RA
!
boot-start-marker
boot-end-marker
!
!
!
no aaa new-model
!
!
!
!
!
!
!
!
!
!
!
!
!
!


!
!
!
!
ip domain name cisco.com
ip cef
no ipv6 cef
!
multilink bundle-name authenticated
!
!
cts logging verbose
!
!
license udi pid CISCO1941/K9 sn FJC2226L3KN
license boot module c1900 technology-package datak9
!
!
username Admin secret 5 $1$yR.j$p8H74mA3ETC.k9GM6yEPF1
!
redundancy
!
!
!
!
!
track 1 ip sla 1 reachability
!
track 10 ip sla 2 reachability
!
ip ssh version 2
!
!
crypto isakmp policy 9
 encr aes
 authentication pre-share
 group 5
 lifetime 14400
!
crypto isakmp policy 10
 encr aes
 authentication pre-share
 group 5
 lifetime 14400
crypto isakmp key cisco1 address 80.0.0.1
crypto isakmp key cisco2 address 80.0.0.2
!
!
crypto ipsec transform-set MYTS esp-aes esp-sha-hmac
 mode tunnel
!
!
!
crypto map MAINMAP 10 ipsec-isakmp
 set peer 80.0.0.1
 set peer 80.0.0.2
 set transform-set MYTS
 match address VPNLIST
!
!
!
!
!
interface Embedded-Service-Engine0/0
 no ip address
 shutdown
!
interface GigabitEthernet0/0
 description WAN
 ip address 80.0.0.3 255.255.255.0
 ip nat outside
 ip virtual-reassembly in
 duplex auto
 speed auto
 crypto map MAINMAP
!
interface GigabitEthernet0/1
 no ip address
 duplex auto
 speed auto
!
interface GigabitEthernet0/1.99
 description LAN
 encapsulation dot1Q 99
 ip address 10.10.10.254 255.255.255.0
 ip nat inside
 ip virtual-reassembly in
!
interface Serial0/1/0
 no ip address
 shutdown
 clock rate 2000000
!
interface Serial0/1/1
 no ip address
 shutdown
 clock rate 2000000
!
interface GigabitEthernet0/0/0
 no ip address
!
interface GigabitEthernet0/0/1
 no ip address
!
interface GigabitEthernet0/0/2
 no ip address
!
interface GigabitEthernet0/0/3
 no ip address
!
interface Vlan1
 no ip address
!
ip forward-protocol nd
!
no ip http server
no ip http secure-server
!
ip nat inside source list 100 interface GigabitEthernet0/0 overload
ip route 172.16.1.0 255.255.255.0 80.0.0.2 track 1
ip route 172.16.1.0 255.255.255.0 80.0.0.1 10 name BCKP track 10
!
ip access-list extended VPNLIST
 permit ip 10.10.10.0 0.0.0.255 172.16.1.0 0.0.0.255
!
ip sla 1
 icmp-echo 80.0.0.2
 frequency 30
ip sla schedule 1 life forever start-time now
ip sla 2
 icmp-echo 80.0.0.1
 frequency 30
ip sla schedule 2 life forever start-time now
!
!
access-list 100 deny   ip 10.10.10.0 0.0.0.255 172.16.1.0 0.0.0.255
!
control-plane
!
!
!
line con 0
line aux 0
line 2
 no activation-character
 no exec
 transport preferred none
 transport output lat pad telnet rlogin lapb-ta mop udptn v120 ssh
 stopbits 1
line vty 0 4
 login
 transport input ssh
line vty 5 15
 login
 transport input ssh
!
scheduler allocate 20000 1000
!
end
```

```title="SA"
!
version 12.2
no service pad
service timestamps debug datetime msec
service timestamps log datetime msec
no service password-encryption
!
hostname SA
!
boot-start-marker
boot-end-marker
!
enable secret 5 $1$oJ0N$QCAnAgNIbbCGWtVDPe.w.1
!
username Admin secret 5 $1$kIj2$LOORc.AbMVmunuz.wAeUa.
!
!
aaa new-model
!
!
aaa authentication login default local
aaa authorization exec default local
!
!
!
aaa session-id common
switch 1 provision ws-c3750-48p
system mtu routing 1500
ip domain-name cisco.com
!
!
!
!
crypto pki trustpoint TP-self-signed-1766857472
 enrollment selfsigned
 subject-name cn=IOS-Self-Signed-Certificate-1766857472
 revocation-check none
 rsakeypair TP-self-signed-1766857472
!
!
crypto pki certificate chain TP-self-signed-1766857472
 certificate self-signed 01
  30820244 308201AD A0030201 02020101 300D0609 2A864886 F70D0101 04050030
  31312F30 2D060355 04031326 494F532D 53656C66 2D536967 6E65642D 43657274
  69666963 6174652D 31373636 38353734 3732301E 170D3933 30333031 30303031
  34355A17 0D323030 31303130 30303030 305A3031 312F302D 06035504 03132649
  4F532D53 656C662D 5369676E 65642D43 65727469 66696361 74652D31 37363638
  35373437 3230819F 300D0609 2A864886 F70D0101 01050003 818D0030 81890281
  8100BBAA 4DF299EE C9CC6322 7B7B56E0 5C995CB6 12AC660D 1771EDE6 F5A530BA
  97F705EC 9A0D6759 4428656A D3258DBB 8B18A721 CAB2349D E00CAA1F 6A677CF8
  26E27061 BA49520A 19CBFA29 8E93C581 BE28AD6A F29E4732 9C52A1AC F20D06D4
  C9B74639 6C39DF5A 7572CC48 3CEA1C13 1E93F766 030722E5 38C1A356 373E2666
  E4C30203 010001A3 6C306A30 0F060355 1D130101 FF040530 030101FF 30170603
  551D1104 10300E82 0C53412E 63697363 6F2E636F 6D301F06 03551D23 04183016
  80144055 71FC6620 887F4A43 3F780CAD 08AF8610 5BC8301D 0603551D 0E041604
  14405571 FC662088 7F4A433F 780CAD08 AF86105B C8300D06 092A8648 86F70D01
  01040500 03818100 27E932C4 68EFCF93 4A579BC5 8EBF99D6 23A240BC 1DD811EF
  7527F21F B32DF4A7 23178B56 7EA7AF48 B2579CED D655C84B A904CF65 847191C8
  A7B0F226 087C71EE 9D2091E7 FD1CBAE5 BF0D0A64 56F57897 AD9613F5 89386CAB
  63758361 4A5BA43F 23BB113D 20DD361F 8AE55FD1 4EC3AFF7 F4E6DED9 536E008B
  0B39FD74 10A77782
  quit
!
!
!
spanning-tree mode pvst
spanning-tree extend system-id
!
vlan internal allocation policy ascending
!
ip ssh version 2
!
!
interface FastEthernet1/0/1
 switchport trunk encapsulation dot1q
 switchport mode trunk
!
interface FastEthernet1/0/2
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/3
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/4
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/5
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/6
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/7
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/8
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/9
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/10
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/11
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/12
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/13
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/14
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/15
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/16
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/17
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/18
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/19
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/20
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/21
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/22
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/23
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/24
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/25
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/26
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/27
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/28
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/29
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/30
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/31
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/32
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/33
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/34
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/35
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/36
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/37
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/38
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/39
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/40
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/41
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/42
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/43
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/44
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/45
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/46
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/47
 switchport access vlan 99
 switchport mode access
!
interface FastEthernet1/0/48
 switchport access vlan 99
 switchport mode access
!
interface GigabitEthernet1/0/1
!
interface GigabitEthernet1/0/2
!
interface GigabitEthernet1/0/3
!
interface GigabitEthernet1/0/4
!
interface Vlan1
 no ip address
!
interface Vlan99
 ip address 10.10.10.253 255.255.255.0
!
ip classless
ip http server
ip http secure-server
!
snmp-server community prtg RO
snmp-server location Site distant
snmp-server enable traps cpu threshold
!
vstack
!
line con 0
line vty 0 4
 transport input ssh
line vty 5 15
 transport input ssh
!
end
```
