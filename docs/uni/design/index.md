---
title: Security by design
description: cours de security by design
---


!!! info "Prof"
    Nadege REYNAUD

## Intro

- Comprendre la démarche de sécu par conception
- Mener une analyse de risques
- Faire le lien entre les aspects fonctionnels et opérationnels de la cybersécu d'une organisation (lien entre risques et failles)

!!! abstract "PSSI"

!!! abstract "Cybersécu"
    Protection, détection, réaction, ghestion de crise

!!! abstract "Humain"
    Formation, entrainement, sensibilisation

### Besoin d'anticipation

- Connaitre les menaces
- Maitriser les vulnérabilité (patch, mitigation des failles si impossible)
- Se protéger en conséquence (actions technique, utilisation d'outils spécifiques ou sensibilisation du personnel)

### Analyse de risques

- Se connaitre: contexte, activités, périmètre, écosystème, parties prenantes
- Connaitre ses activités critiques et ses données sensibles
- Evaluer les risques et savoir les priorétiser
- S'organiser en conséquence

### Analyse de risques cyber

- Se connaitre: contexte, activités, périmètre, écosystème, parties prenantes
- Connaitre ses systèmes critiques et ses données sensibles (savoir où elles se trouvent)
- Connaitre ses besoins de sécurité (dispo, intégrité, confidentialité, tracabilité) et de conformité
- Avoir conscience des menaces et des vulnérabilités
- Evaluer les risques et savoir lesquels traiter en priorité
- Etablir des plans de sécurisation et s'y tenir, gérer les risques.

## Security by design

Concevoir des produits et des logiciels fondamentalement sécurisés.
La sécurisation se réfléchit et s'opère dès la conception, en prenant en compte les risques.
Elle est anticipée.

### Où s'opère la secu by design?

- Code ([OWASP](https://owasp.org/www-project-developer-guide/draft/), DevSecOps)
- Architecture (ANSII)
- Projets (implémentation d'une nouvelle fonctionnalité) (EBIOS RM, ISP)
- Stratégies (ISO27001, NIST)

#### Le code

Eviter de générer des applis faillibles dès le départ.
Il faut considérer au plus tôt les aspects relatifs à la sécurité pour anticiper au maximum l'introduction de vulnérabilités.

##### DevSecOps

Intégration de la sécurité des applications plus tôt dans le cycle de développement.
Anticiper pour éviter la correction de vulnérabilités a posteriori, alors plus couteuse et plus compliquée.

##### OWAPS

Open WorldWide Applicatoon Security Project.

Travaille sur un guide pour les développeurs, mais également beaucoip de ressources. Les principes le plus souvent appliqués sont:

- Le moindre privilège
- La séparation des tâches
- La défense en profondeur
- Le principe de Zero Trust

#### Architecture

L'objectif est de protéger au mieux les systèmes critiques et les données sensibles d'une organisation, grâce à des principes d'architectures sécurisées.

Cela permet:

- d'éviter la propagation d'attaques
- de conserver un bon niveau de sécurité malgré les migrations
- de concevoir des architectures permettant de satisfaire les besoins de sécurité

#### Projets

L'activité principale réside dans l'analyse de risques.

Des méthodes existent, comme EBIOS RM, ou des normes comme ISO27005, mais on peut également construire sa propre méthode.

Les étapes fondamentales sont:

- Identifier les actifs
- Identifier le personnes responsables
- Identifier les vulnérabilités
- Identifier les menaces
- Identifier les impacts
- Evaluer la vraisemblance
- Evaluer les nivbeaux de risques

EBIOS RM: Expression des besoins et identification des objectifs de sécurité. 
outil complet de gestion des risques SSI conforme au RGS et aux normes ISO27001 et 27005. 
Elaboration par l'ANSSI et le Club EBIOS.

!!! abstract "Risque"
    Scénario qui combine un évènement redouté et un ou plusieurs scénarios de menaces. On estime son niveau par sa gravité (hauteur des impacts) et sa vraisemblance (possibilité qu'il se réalise).
