---
title: Sécurité informatique
description: Cours de sécurité informatique
---

!!! warning "Ce cours c'est le **zbeul**"

Kerberos: gestion de ressources et utilisateurs basé sur LDAP. Domaine NIS?

- BtC: Business to Client
- BtE: Business to Employee (Ypareo)
- BtB: Business to Business (XML app to server)

SOA: Source Of Authority

Metavers: garde toutes les identités dans le temps d'une personne   

Schiboulette (Linux) équivaut a AD FS

Au sein d'un meta:

 - Fournisseurs d'ID
 - Parties de confiance exigent les ID
 - Sujets qui revendiquent les ID

 lois sur l'ID

 - Les gens doivent être concentants d'en avoir une
 - Divulgation minimale pour usage contraint
 - Choix entre plusieurs opératuers

AirBack ? droits dynamiques ? 

Kerberos permet un tiering des comptes et un accès dynamiques aux fichiers

PKI: Auth par certificat

IAM: Identity Access Management

Composants de l'IAM



Federation des outils AFORP pour n'avoir qu'1 compte a créer + système pour changer le mdp

On aura une Certification Practice Statement (CPS) a faire

- Classifier les données par sensibilité, cycle de vie 
- Définition de la sécurité (physique, logique)
- Risques et menaces
- Mesures a prendre pour protéger les données et actifs

rfc2196

RFC3647: ce qu'on va faire

Certification Practice Statement CPS

1. Génération clé
2. Génération d'une requête vers cd - envoie le rôle puis la clé publique
3. La CA signe le certidficat
4. Importation du certificat

Criteres communs: EAL, niveau de sécu d'un logiciel


Instal ad: Windows>Acs? fichier important a utiliser AU DEBUT de l'instal
Crypto: ksp

surveiller pki:

- date des certificats
- fonction des AIA
- Fonction de la haute dispo
- Controle des contraintes
- Vérifier les stratégies d'émission
