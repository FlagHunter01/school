---
title: Défense / supervision / Gestion d'incidents et de crise
description: Cours de détection et de réaction aux menaces de sécurité
---

!!! info "Prof"
    [Olivier CALEFF <paris.saclay@caleff.com>](mailto:paris.saclay@caleff.com)
    

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

### ISO27035

Eléments a retenir:

- Approche structurée
- Procesus de gestion des incidents de sécurité
- Des phases de la gestion des incidents
- Une équipe de réponse aux incidents de sécurité (CSIRT)
- Des indications du processus de gestion des incidents de sécurité avec les autres processus dans l'organisme
- Une organisation du processus de gestion des incidents de sécurité

Phases : 4+1

1. Planifier et préparer
- Détecter & signaler
- Evaluer & décider
- Répondre
- Tirer les enseignements

#### Planifier et préparer

- politique de gestion des incidents de sécurité
- Aspects légaux et reglementaires de la gestion d'incidents
- Catégories d'incidents de sécurité
- Méthodes de classement ou de typologie d'incidents de sécurité CVSS, ISO27035
- Intéractions avec d'autres référentiels ou d'autres politiques
- Modélisation du système de gestion des incidents de sécurité
- Procédures
- Enregistrement des évènements de sécurité et déclaration des évènements de sécurité
- Définition des activités d'une équipe de réponse aux incidents de sécurité (CSIRT)
- Mise en oeuvre de son CSIRT
- Support technique et opérationnel
- Formation et sensibilisation
- Test de son système de gestion des incidents de sécurité et des exercices

#### Détecter et signaler

- Activités de l'équipe opérationnelle de détection des incidents de sécurité de l'information
    - Run
- Détection d'évènements
    - Positionnement, seuils, suivi
- Rapport d'activité sur les évènements
    - Reporting
- Test d'efficacvité
    - Exercices, audit

#### Evaluer et décider

- Activités de l'équipe opérationnelle d'analyse des incidents de sécurité de l'information
- Analyse immédiate et décision initiale
- Appréciation et confirmation de l'incident.

Il est primordial de réévaluer au fur et a mesure du développement de l'incident. 

#### Réponse a incident

- Réponse immédiate
- Réponse a postériori
- Gestion d ela crise
- Analyse inforensique
- Communication
- Escalade
- Journalisation de l'activité et changement

#### Tirer les enseignements

- Faire un bilan
- Capitaliser
- Féfinir les axes d'amélioration
- Améliorer la capacité de réaction en cas de nouvelle occurence d'un incident similaire
- Limiter les risques d'occurence d'un incident similaire

### Killchain

- Detect
- Deny
- Disrupt
- Degrade
- Decieve
- Destroy

!!! warning "J'ai lâché après"
    C'est assez confus, je vois pas le rapport avec le court et ce qu'il raconte.<br>
    J'espère qu'on aura son diapo

[https://www.first.org/standards/frameworks/csirts/csirt_services_framework_v2.1](Lien du first)

---

## Devoir 

!!! info "Consignes et définitions"
    Finir le document. Procédures a établir pour détection efficaces. 

    - IDS: Système de Détection des Intrusions: détecte les pattenrs d'attaques connues dans le trafic réseau. 
    - IPS: Analyse les paquet
    - EDR: Endpoint Detection and Response: Antivirus sur les terminaux
    - Plus généralement SIEM Security Information and Event Management: collecte, analyse et archivage des informations sur les évènements de sécurité 

### Objectif

Détecter efficacement les incidents de sécurité relatifs au web. 

### Types d'incidents identifiés

- Accès (direct) à des ressources interdites (lecture ou modification)
    - Injection de code dans le PHP / SQL
- Usurpation d'identité
    - Vol de session
    - Authentification [Formation des utilisateurs - notif de connexion]
- DOS
- Fuite d'informations confidentielles [surveillance des infromations fuitées connues]

### Solutions de détection

Les solutions techniques reposent sur l'implémentation d'un SIEM. 
La détection d'évènements anormaux doit être automatisée au maximum. Ce qui ne peut pas être automatisé doit générer des alertes qui notifient les bonnes personnes le plus vote possible. 

- Accès direct à des ressources interdites
    - L'injection peut être détectée par des logiciels comme Snort. L'interaction avexc des fichiers sensibles devrait &galement être loguée et notifiée. 
- Usurpation d'identité
    - Le vol de session est plus facile a contrer qu'a identifier. Bien qu'il est possible de détecter des chaines qui indiquent une attaque XSS (injection d'un script a travers un lien sur un autre site), ou de détecter des chevaux de troie avec un EDR sur le client, l'action la plus productive reste la sécurisation des méthodes de connexion. 
    - Les tentatives d'authentification doivent notifier immédiatement le propriétaire du compte afin qu'il puisse identifier une tenttative de connexion malfaisante. En cas d'échec d'authentification, le SIEM doit également notifier l'équipe de sécurité. 
- Les attaques DOS et DDOS peuvent être détectées en comparant le trafic actuel avec le trafic habituel ou prévu. 
- Il est sage d'automatiser la recherche d'informations fuitées sur des bases d'information dédiées pour que l'équipe de sécurité soit notifiée en cas de fuite d'informations. 

En plus des procédures techniques ci-dessus, il est important de préparer le personnel pour maximiser l'efficacité du dispositif. 

- Les messages d'alerte doivent être les plus précis possibles et cibler le personnel compétent.
- Des procédures calires doivent être établies pour chaque type d'incident identifié. 
- Le personnel de l'équipe de sécurité doit être entrainé avec des répétitions (annoncées ou non)
- Les utilisateurs (hors équipes IT) doivent être sensibilisés et formés aux "gestes de premiers secours". Par exemple, s'ils sont notifiés d'une connexion dont ils ne sont pas les auteurs, ils doivent savoir qui et comment prévenir. 
- Il est important de former l'ensemble des utilisateurs, notamment les membres de la direction qui ont souvent des droits à outrance.  

