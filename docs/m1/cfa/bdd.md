---
title: Bases de données
description:  Cours de bases de données
---


!!! info "Infos prof"
    [frederic.cagnache@cfa-afti.fr](mailto:frederic.cagnache@cfa-afti.fr)

## Définitions

!!! abstract "Définition de 'information'"
    Une information est la distinction d'un état parmis *n*.

!!! abstract "Définition de 'base de donnée'"
    Une base de données sert à assurer la persistance des données.

!!! abstract "Définition de 'SGBD'"
    Le SGBD est un outil permettant de gérer les bases de données.

## Historique des modèles

- Modèle hiérarchique
  - ISAM, VSAM
- Modèle réseau (années 60)
  - CODASYL
- Modèle relationnel (années 70)
  - Oracle
  - MySQL
  - MariaDB

## Languages

- COBOL-CODASYL (description ++, traitement --)
- SQL

## Modèle relationnel

- Une BDD est constituée de tables
  - Les tables sont constituées de tuples

## SQL

- Langage déclaratif
  - On demande ce que l'on souhaite, on ne décrit pas comment l'obtenir comme en C.
  - C'est le rôle du SGBD d'obtenir ce que l'on veut

## Actions de base sur une BDD

- Créer une base
- Créer une table
- Peuplement
  - Par script
  - Par import
- Accéder aux données
  - SELECT
    - SELECT champs FROM table WHERE condition
      - SELECT champ1, champ2 FROM table
      - SELECT * FROM client WHERE ville='paris'
  - Jointures
    - SELECT * FROM a INNER JOIN b ON a.key = b.key

## Premier exercice

- Créer BDD géolocalisation
- Table villes
- Table personnes avec nom, prénom, rue, ville, CP
- La peupler
- Extraire la liste des départements présents dans la table villes
- Extraire la liste des noms de famille dans ...
- [...] par ordre alphabétique
- Extraire la liste des noms et des départements ou chaque personne habite
- [...] par ordre alphabétique

```sql title="Création des tables"
/* Créer la table geolocalisation */


CREATE TABLE `villes` (
  `ID` varchar(5) DEFAULT NULL,
  `DEP` varchar(3) DEFAULT NULL,
  `Nom` varchar(45) DEFAULT NULL,
  `CP` varchar(125) DEFAULT NULL,
  `n_INSEE` varchar(7) DEFAULT NULL,
  `Arr` varchar(3) DEFAULT NULL,
  `CT` varchar(4) DEFAULT NULL,
  `Pop_2010` int(11) DEFAULT NULL,
  `Superficie` float(12,5) DEFAULT NULL,
  `Lon` float(12,5) DEFAULT NULL,
  `Lat` float(12,5) DEFAULT NULL,
  `Alt_min` int(11) DEFAULT NULL,
  `Alt_max` int(11) DEFAULT NULL
)


CREATE TABLE `geolocalisation`.`personnes` (`nom` VARCHAR(50) NOT NULL , `prenom` VARCHAR(50) NOT NULL , `rue` VARCHAR(50) NOT NULL , `ville` VARCHAR(50) NOT NULL , `CP` INT(10) NOT NULL) ENGINE = InnoDB;


INSERT INTO `personnes` (`nom`, `prenom`, `rue`, `ville`, `CP`) VALUES ('BON', 'Jean', 'rue de l\'industrie', 'Arnaque la Poste', '87160');
INSERT INTO `personnes` (`nom`, `prenom`, `rue`, `ville`, `CP`) VALUES ('TOUILLE', 'Sacha', 'rue du ruisseau', 'Condom', '32100');


INSERT INTO `villes` VALUES ('1','01','Ozan','01190','01284','2','26',618,6.60000,4.91667,46.38330,170,205),('2','01','Cormoranche-sur-Sa¶ne','01290','01123','2','27',1058,9.85000,4.83333,46.23330,168,211),('3','01','Plagne','01130','01298','4','3',129,6.20000,5.73333,46.18330,560,922),('4','01','Tossiat','01250','01422','2','25',1406,10.17000,5.31667,46.13330,244,501),('5','01','Pouillat','01250','01309','2','33',88,6.23000,5.43333,46.33330,333,770),('6','01','Torcieu','01230','01421','1','28',698,10.72000,5.40000,45.91670,257,782),('7','01','Replonges','01620','01320','2','2',3500,16.60000,4.88333,46.30000,169,207),('8','01','Corcelles','01110','01119','4','6',243,14.16000,5.58333,46.03330,780,1081),('9','01','PÚron','01630','01288','3','12',2143,26.01000,5.93333,46.20000,411,1501),('10','01','Relevant','01990','01319','2','30',466,12.38000,4.95000,46.08330,235,282),('11','01','Chaveyriat','01660','01096','2','10',927,16.87000,5.06667,46.18330,188,260),('12','01','Vaux-en-Bugey','01150','01431','1','17',1169,8.22000,5.35000,45.91670,252,681),('13','01','Maillat','01430','01228','4','22',668,11.31000,5.55000,46.13330,497,825),('14','01','Faramans','01800','01156','2','19',681,11.22000,5.11667,45.90000,255,306),('15','01','BÚon','01350','01039','1','9',373,10.30000,5.75000,45.83330,228,1412),('16','01','Saint-Bernard','01600','01339','2','34',1375,3.15000,4.73723,45.94500,167,198),('17','01','Rossillon','01510','01329','1','36',148,8.07000,5.60000,45.83330,324,1022),('18','01','Pont-d\'Ain','01160','01304','2','25',2627,11.22000,5.33333,46.05000,232,314),('19','01','Nantua','01460','01269','4','22',3713,12.79000,5.61667,46.15000,427,1125),('20','01','Chavannes-sur-Reyssouze','01190','01094','2','26',680,16.55000,5.00000,46.43330,175,218),('21','01','Neuville-les-Dames','01400','01272','2','10',1504,26.59000,5.00000,46.16670,210,271),('22','01','Flaxieu','01350','01162','1','36',63,2.79000,5.73333,45.81670,225,385),('23','01','Hotonnes','01260','01187','4','6',306,28.40000,5.68333,46.00000,636,1338),('24','01','Saint-Sorlin-en-Bugey','01150','01386','1','17',1061,9.07000,5.36667,45.88330,196,700),('25','01','Songieu','01260','01409','1','9',130,20.58000,5.70000,45.96670,567,1275),('26','01','Virieu-le-Petit','01260','01453','1','9',309,16.36000,5.71667,45.90000,419,1524),('27','01','Saint-Denis-en-Bugey','01500','01345','1','1',2178,2.61000,5.33333,45.95000,234,338),('28','01','Charnoz-sur-Ain','01800','01088','2','19',911,6.62000,5.21667,45.86670,203,244),('29','01','Chazey-sur-Ain','01150','01099','1','17',1464,21.95000,5.25000,45.90000,202,261),('30','01','Marchamp','01680','01233','1','18',118,13.11000,5.55000,45.78330,400,940),('31','01','Culoz','01350','01138','1','31',2909,19.36000,5.78333,45.85000,226,1430),('32','01','Mantenay-Montlin','01560','01230','2','29',288,10.80000,5.08333,46.41670,180,222),('33','01','Marboz','01851','01232','2','11',2182,40.14000,5.25000,46.33330,194,240),('34','01','Foissiat','01340','01163','2','21',1912,40.36000,5.18333,46.36670,186,228),('35','01','Treffort-Cuisiat','01370','01426','2','33',2204,39.41000,5.36834,46.27140,221,681),('36','01','Izieu','01300','01193','1','4',201,7.67000,5.63333,45.65000,211,758),('37','01','Saint-╔tienne-du-Bois','01370','01350','2','33',2441,28.38000,5.28333,46.28330,213,259),('38','01','Hauteville-Lompnes','01110','01185','1','15',4044,50.34000,5.60000,45.96670,455,1240),('39','01','Saint-Trivier-sur-Moignans','01990','01389','2','30',1877,41.99000,4.90000,46.06670,230,289),('40','01','Peyriat','01430','01293','4','16',171,5.96000,5.51667,46.15000,558,825),('41','01','╔vosges','01230','01155','1','28',140,12.08000,5.50000,45.95830,560,1001),('42','01','Poncin','01450','01303','4','24',1644,19.77000,5.40000,46.08330,240,540),('43','01','Crans','01320','01129','2','8',269,13.23000,5.21667,45.96670,249,322),('44','01','MontrÚal-la-Cluse','01460','01265','4','22',3457,12.83000,5.57084,46.18670,473,960),('45','01','Cleyzieu','01230','01107','1','28',135,7.82000,5.43333,45.90000,440,927),('46','01','Lompnieu','01260','01221','1','9',122,11.35000,5.65000,45.96670,524,1241),('47','01','Villereversure','01250','01447','2','7',1208,17.45000,5.38333,46.18330,279,480),('48','01','Saint-Martin-du-Mont','01160','01374','2','25',1651,28.09000,5.33333,46.10000,246,556),('49','01','Saint-Genis-Pouilly','01630','01354','3','13',8914,9.77000,6.01667,46.25000,419,502),('50','01','Bolozon','01450','01051','4','16',94,4.92000,5.48333,46.20000,261,673),('51','01','Confranþon','01310','01115','2','21',1157,18.17000,5.06667,46.26670,192,224),('52','01','Lochieu','01260','01218','1','9',91,7.07000,5.71667,45.93330,479,1426),('53','01','Chanoz-ChÔtenay','01400','01084','2','10',706,13.42000,5.03333,46.18330,194,268),('54','01','Villebois','01150','01444','1','17',1153,14.46000,5.43333,45.85000,195,960),('55','01','Ceignes','01430','01067','4','16',265,10.01000,5.50000,46.11670,580,862),('56','01','Saint-Didier-sur-Chalaronne','01140','01348','2','32',2776,24.98000,4.81667,46.16670,167,223),('57','01','Revonnas','01250','01321','2','7',788,7.75000,5.33333,46.16670,255,504),('58','01','Bourg-Saint-Christophe','01800','01054','2','19',1173,8.98000,5.16667,45.88330,207,305),('59','01','Condeissiat','01400','01113','2','10',756,21.64000,5.08333,46.16670,232,268),('60','01','Pirajoux','01270','01296','2','11',360,12.99000,5.30000,46.38330,192,237),('61','01','Chalamont','01320','01074','2','8',2322,32.88000,5.16667,46.00000,269,330),('62','01','Le Plantay','01330','01299','2','8',540,19.96000,5.08333,46.01670,267,286),('63','01','Versailleux','01330','01434','2','8',332,18.77000,5.10000,45.98330,274,303),('64','01','Montagnat','01250','01254','2','39',1646,13.75000,5.28333,46.16670,229,282),('65','01','Vieu','01260','01442','1','9',380,6.54000,5.68333,45.90000,280,540),('66','01','Saint-AndrÚ-de-Corcy','01390','01333','2','42',2991,20.73000,4.95000,45.91670,279,306),('67','01','Bressolles','01360','01062','2','20',709,7.73000,5.10000,45.86670,205,292),('68','01','PÚronnas','01960','01289','2','39',6054,17.55000,5.20000,46.18330,223,277),('69','01','Colomieu','01300','01110','1','4',115,5.96000,5.61667,45.73330,319,476),('70','01','Monthieux','01390','01261','2','35',599,10.75000,4.93333,45.95000,281,311),('71','01','Saint-Jean-sur-Reyssouze','01560','01364','2','29',744,27.48000,5.06667,46.40000,178,218),('72','01','Garnerans','01140','01167','2','32',656,8.57000,4.83333,46.20000,168,215),('73','01','Montrevel-en-Bresse','01340','01266','2','21',2362,10.27000,5.13333,46.33330,192,220),('74','01','Conand','01230','01111','1','28',104,15.28000,5.46667,45.88330,351,1021),('75','01','Challes-la-Montagne','01450','01077','4','24',179,7.65000,5.46667,46.13330,440,700),('76','01','Mogneneins','01140','01252','2','32',727,8.57000,4.81667,46.13330,168,238),('77','01','Thoissey','01140','01420','2','32',1540,1.34000,4.80000,46.16670,168,178),('78','01','Chaleins','01480','01075','2','30',1165,17.00000,4.80000,46.03330,193,267),('79','01','Neuville-sur-Ain','01160','01273','2','25',1571,19.79000,5.36667,46.08330,242,427),('36828','971','Saint-Martin','97150','97127','0','NULL',36979,53.20000,18.09130,-63.08290,NULL,NULL),('36830','975','Saint-Pierre-et-Miquelon','97500','97501','0','NULL',6080,242.00000,46.71070,1.71819,NULL,NULL);
```

```sql title="Réponses à l'exercice"
SELECT DEP FROM villes;


SELECT nom FROM personnes;


SELECT nom FROM personnes ORDER BY nom;


SELECT villes.nom, villes.DEP FROM villes, personnes WHERE personnes.ville = villes.nom


SELECT villes.nom, villes.DEP FROM villes, personnes WHERE personnes.ville = villes.nom ORDER BY villes.nom
```

## Modèle antité - association

Permet de conduire une analyse pour mettre à plat toutes les informations qui nous sont présentées.

En gros on fait de l'UML

- Entité
  - Elément statique
- Association
  - Relation entre les entités
- Cardinalité
  - Définit le nombre d'occurrences de l'entité impliquées dans une association

## Formes normales

- On définit 6 formes normales
  - 1FN
  - 2FN
  - 3FN
  - FNBC
  - 4FN
  - 5FN
  - FNDC
  - ?

Chaque forme normale supérieure est définie à partir de la précédente.

### Notion de clé

- Une clé est un attribut (champ ou colonne) choisi
- Une clé primaire est un attribut d'une relation qui permet de définir un identifiant unique pour un tuple dans la relation.
- Il n'est pas possible un tuple qui a pour valeur une clé primaire déjà utilisée.

### Forme normale 1

- Une relation (ayant par définition une clé) dont les attributs possèdent une valeur **sémantiquement atomique** (le sens est changé au changement d'un caractère? )
  - Ex: date ou points d'un polygone
  - Un attribut est atomique si aucune subdivision de l'information initiale n'apporte une information supplémentaire ou complémentaire
  - Le non-respect de la première forme normale constitue une des plaies les plus importantes en matière de bases de données relationnelles et a des conséquences graves (?)

### Forme normale 2

- La base doit être en forme normale 1
  - Les attributs d'une relation sont divisés en deux groupes: le premier groupe est composé de la clé et le deuxième groupe est composé des autres attributs
  - Tout attribut du deuxième groupe ne peut pas dépendre d'un sous-ensemble du premier groupe mais que de son intégralité.
- Une relation ayant une clé formée d'un seul attribut est forcément une normale 2

### Forme normale 3

- La BDD est en forme normale 2
- Les attributs d'une relation sont divisés en deux groupes: la clé et les autres attributs
- Tout attribut du deuxième groupe ne peut pas dépendre d'un sous-ensemble d'autres attributs du second groupe.
- Une relation en forme normale 2 et qui a au plus un attribut qui n'appartient pas à la clé est forcément de forme normale 3.
- La 3^e^ forme normale ne garantit pas l'absence de redondance des données

### Forme normale FNBC

- Boyce-Codd
- Respectant la forme normale 3 et dont tous les attributs non-clé ne sont pas source de dépendance fonctionnelle vers une partie de la clé.

## Projet

- Définissez une BD contenant les infos usuelles de personnes: nom prénom, âge, adresse...
- On souhaite pouvoir y adjoindre des données de géolocalisation
- Et de consommation de chauffage de différentes sources d’énergie auprès de fournisseurs d’énergie
- On souhaite pouvoir en extraire des données pour une analyse de besoin de distribution d’énergie selon les localisations BDD F. Cagnache14/02/2023 21
- Proposez les différentes tables à définir dans cette BD de manière à ce qu’elle soit en 3FN
- Peuplez-les
- Démontrez que cette base est en 3 FN
- Proposez les requêtes SQL permettant de
présenter les informations facilitant la distribution d’énergie des abonnés (personnes) par département sachant que les fournisseurs ont des centres de distribution répartis seulement dans certains départements
