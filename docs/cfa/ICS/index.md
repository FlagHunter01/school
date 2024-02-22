---
title: Sécurité ICS
description: Cours de sécurité ICS
---

!!! info "Prof"
    - Azzeddine RAMRAMI
    - ENSTA / IP
    - [azzeddine.ramrami@owasp.org](mailto:azzeddine.ramrami@owasp.org)

Mieux que Hack the Box: [seedsecuritylabs.org](https://seedsecuritylabs.org)

Certif SANS: [SANS.org](https://www.sans.org/cyber-security-courses/advanced-exploit-development-penetration-testers/)

Pour utiliser Wireshark sur un switch, il faut mettre son port en mode SPAN pour que tout le traffic soit mirror dessus. 

## Ethical hacking

### Méthodes

- CEH v12 
- CPTE Mile2
- CPTS
- OSTMM

Toutes ses méthodes ont 3 phases:

- Information gathering
    - 3 phases de préattaque (?)
        - Information Gathering
            - Google Dork
            - OSINIT
            - whois
            - Données publiqus et réseaux sociaux
                - fingerprinting
                - footprinting
        - Detecting live system
            - Targets:
                - IP, plage IP, Site web, PLC, RTU etc
                - Protooles: IP, IoT (Zigbee, Sigfox, Lora etc), Modbus, TCP/IP
            - Scanning
                - nmap
                - hping3
                - Versions des OS et software
            - Enumeration:
                - shares
                - passwords
    - 1 phase de Vulnerability Assessment
        - Confirmation des CVE et CWE trouvés 
- Exploitation
    - Option 1: NOk (On n'arrive a rien à part un DOS ou DDOS)
    - Option 2: Ok
- Post-exploitation
    - Maintaining access (Backdoor (C&C ([Control & Command](https://www.varonis.com/blog/what-is-c2))), pivoting ...)
    - Cover your tracks (Logs read by SIEM, File Integrity Monitoring (FIM)(Ex: Tripwire) etc)

### Principaux DLL

- kernel32
- advapi
- user32
- ntdll
- wsock32
- ws2_32
- netapi32
