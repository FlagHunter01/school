---
title: Défense / supervision / Gestion d'incidents et de crise
---

!!! info "Prof"
    Olivier CALEFF

## Intro

Surveiller **toutes** les couches du système d'information.

Détecter **tous** les incidents de sécurité, qu'il ssoient liés à un problème technique, **humain** ou **environnemental**.

Réagir face à un **incident** en prenant en compte toutes les informations liées à l'évènement et en y remédiant en s'appuyant sur une **procédure** liant le traitement technique et **organisationnel** de l'incident.

- NOC (Network Op Center)
- SOC (Secu)
- VOC (?)

- SIEM IA
- SOAR (Machine Learning)

## Cyber Security Framework 1.1

- Identify
- Protect
- Detect
- Respond
- Recover


## Protection

Logs DHCP stonks    

pi-hole.net

Train le personnel, répéter des simulations pour que ca reste frais

## Contexte

Qui nous attaque? 

Il faut faire les vérifs, mais aussi vérifier si les vérifs ont bient été faites

Le principe de base est l'automatisation!

## Erreurs

- Négliger le facteur humain
- Tout miser sur la technique
- Négliger la gouvernance
- Mal définir ou évaluer le périmètre
- Mal maîtriser son infrastructure
- Détruire des indices (on commence par faire un snapshot avant de toucher)

## Détection

C'est le fait de repérer pour prévenir et alerter.

Moyens:

- EDR/XDR/comportemental
- Logs
- SIEM
- SOAR (orchestrateur, il décide s'il faut notifier et s'il faut mener des actions avec des procédures prédéfinies. Il est complémentaire au SIEM)
- IDS/IPS
- Proxy
- Surveillance physique
    - Locaux sensibles:
        - Datacenters
        - Locaux techniques
    - Sécurité:
        - Fermer a clé (bof)
        - Badges avec logs
- ==Les gens de la sécurité (formés et prêts)==
    - Lois
    - Gouvernance
    - ==Procédures==
- Les utilisateurs (c'est les capteurs les plus performants s'ils sont bien formés)
    - Il faut leur parler en symptomes

Choses a surveiller:

- Web/CMS
- "Cloud de fichiers"
- Messagerie
- Bases de données
- VPN
- Backups

Tout ceci est lié a deux choses: les logs et l'authentification.

Il existe plusieurs aspects:

- Organisationnel
- Technique
- Humain
- Decisionnel

---

Associations a rejoindre:

- OSIR (?)



## Gestion des incidents et cyberrésilience

### Travail d'équipe

- Informatique (copains mais n'aiment pas les contraintes de la sécu)
- Sécu (nous)
- Métiers (les users)
- Règlementaire (lois)
- Communication 

### Les erreurs

- Negliger le facteur humain
- Tout miser sur la technique
- Negliger la gouvernance
- Mal définir le périmètre
- Ne pas maitriser son infrastructure
- Détruire les indices

### Trucs a lire

- NIST SP 800
- SANS
- ENISA
- ISO2735 (traitement d'un incident de sécurité)
    - Planifier et préparer l'intervention (téléphone sur soi, doc hors ligne)
    - Détecter et signaler
    - Evaluer et décider
    - Répondre
    - ==Tirer les enseignements==

### Terminologie

- Computer Emergency Response Team (gestion d'incidents)
- Computer Security Incident Response Team (same shit as previous)
- Product Security Incident Response Team (Orienté produit)
- Information Sharing and Analysis Center (Regroupement d'équipes de sécu d'un même secteur (santé par ex). Coop inter-entreprise.)
- Security Operations Center (sécurité opérationnelle)

### Contexte interne

- Outils
    - Inventaire
    - Annuaire
- Procédures
    - Veille
    - Incidents & crises
- Personnels
    - CSIRT & IT
    - Constituents (?)
- Gouvernance
    - Rôles
    - Responsabilités
- Communication
    - Mode normal & mode dégradé
    - Populations internes et externes

---

## Notes de groupe

- Silvain
- Mergrim
- Tim
- Rudi

- Cross site scripting
    - PHPIDS avec expressions régulières
- Injection
- Exéciution malveillante  de fichiers PHP
    - Logs PHP
- Insecure object reference
    - Patterns des requetes 
Cross site request forgery
Fuite d'info et mauvaise gestion d'erreur
Problèmes d'authentification et de session
Erreurs de restriction d'URL
bots - Comportemental
DOS

### Prochaine fois

Finir le document. Procédures a établir pour détection efficaces. 
