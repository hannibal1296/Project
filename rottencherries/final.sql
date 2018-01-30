-- MySQL dump 10.13  Distrib 5.7.20, for osx10.13 (x86_64)
--
-- Host: localhost    Database: RottenCherries
-- ------------------------------------------------------
-- Server version	5.7.20

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Departments`
--

DROP TABLE IF EXISTS `Departments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Departments` (
  `d_id` int(11) NOT NULL,
  `d_name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`d_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Departments`
--

LOCK TABLES `Departments` WRITE;
/*!40000 ALTER TABLE `Departments` DISABLE KEYS */;
INSERT INTO `Departments` VALUES (1,'소프트웨어대학'),(2,'정보통신대학');
/*!40000 ALTER TABLE `Departments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Lectures`
--

DROP TABLE IF EXISTS `Lectures`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Lectures` (
  `l_id` varchar(20) NOT NULL,
  `l_p_id` int(11) DEFAULT NULL,
  `semester` int(11) DEFAULT NULL,
  `l_name` varchar(20) DEFAULT NULL,
  `l_credit` int(11) DEFAULT NULL,
  PRIMARY KEY (`l_id`),
  KEY `l_p_id` (`l_p_id`),
  CONSTRAINT `lectures_ibfk_1` FOREIGN KEY (`l_p_id`) REFERENCES `Professors` (`p_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Lectures`
--

LOCK TABLES `Lectures` WRITE;
/*!40000 ALTER TABLE `Lectures` DISABLE KEYS */;
INSERT INTO `Lectures` VALUES ('CSE3007-41_201709',2016001,201709,'데이터베이스',3),('CSE3007-42_201609',2016004,201609,'데이터베이스',3),('CSE3007-42_201703',2016003,201703,'데이터베이스',3),('CSE3007-42_201709',2016002,201709,'데이터베이스',3),('SWE3024-41_201709',2016001,201709,'컴퓨터네트웍개론',3),('SWE3024-42_201709',2016002,201709,'컴퓨터네트웍개론',3),('SWE3024-43_201709',2016003,201709,'컴퓨터네트웍개론',3),('SWE3024-44_201709',2016004,201709,'컴퓨터네트웍개론',3);
/*!40000 ALTER TABLE `Lectures` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Majors`
--

DROP TABLE IF EXISTS `Majors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Majors` (
  `m_d_id` int(11) NOT NULL,
  `m_id` int(11) NOT NULL,
  `m_name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`m_id`,`m_d_id`),
  KEY `m_d_id` (`m_d_id`),
  CONSTRAINT `majors_ibfk_1` FOREIGN KEY (`m_d_id`) REFERENCES `Departments` (`d_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Majors`
--

LOCK TABLES `Majors` WRITE;
/*!40000 ALTER TABLE `Majors` DISABLE KEYS */;
INSERT INTO `Majors` VALUES (1,1,'컴퓨터공학과'),(2,1,'전기전자공학부'),(1,2,'소프트웨어공학과'),(2,2,'반도체시스템공학과');
/*!40000 ALTER TABLE `Majors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Professors`
--

DROP TABLE IF EXISTS `Professors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Professors` (
  `p_id` int(11) NOT NULL,
  `p_d_id` int(11) DEFAULT NULL,
  `p_l_name` varchar(10) DEFAULT NULL,
  `p_f_name` varchar(10) DEFAULT NULL,
  `p_gender` char(1) DEFAULT NULL,
  `p_office_loc` int(11) DEFAULT NULL,
  `p_office_num` varchar(15) DEFAULT NULL,
  `p_email` varchar(40) DEFAULT NULL,
  `have_kname` char(1) DEFAULT NULL,
  PRIMARY KEY (`p_id`),
  KEY `p_d_id` (`p_d_id`),
  CONSTRAINT `professors_ibfk_1` FOREIGN KEY (`p_d_id`) REFERENCES `Departments` (`d_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Professors`
--

LOCK TABLES `Professors` WRITE;
/*!40000 ALTER TABLE `Professors` DISABLE KEYS */;
INSERT INTO `Professors` VALUES (2016001,1,'이','종욱','M',85464,'031-570-3004','jongwuklee@skku.edu','Y'),(2016002,1,'김','유성','M',85462,'031-570-3005','yskim525@gmail.com','Y'),(2016003,2,'황','지영','F',27326,'031-570-3006','jjwhang@skku.edu','Y'),(2016004,2,'호르헤','로드리고','M',85465,'031-570-3007','rodrigo@skku.edu','N'),(2016005,2,'이','종욱','F',85467,'031-570-3008','jwl@skku.edu','Y'),(2016006,2,'이화','종욱','F',85460,'031-570-3009','jwlf@skku.edu','Y');
/*!40000 ALTER TABLE `Professors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `RATINGS`
--

DROP TABLE IF EXISTS `RATINGS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RATINGS` (
  `r_id` int(11) NOT NULL,
  `r_s_id` varchar(12) DEFAULT NULL,
  `r_l_id` varchar(20) DEFAULT NULL,
  `exam_rating` float(3,2) DEFAULT NULL,
  `quiz_rating` float(3,2) DEFAULT NULL,
  `hw_rating` float(3,2) DEFAULT NULL,
  `att_rating` float(3,2) DEFAULT NULL,
  `lec_rating` float(3,2) DEFAULT NULL,
  `avg_rating` float(3,2) DEFAULT NULL,
  `comment` varchar(140) DEFAULT NULL,
  PRIMARY KEY (`r_id`),
  KEY `r_s_id` (`r_s_id`),
  KEY `r_l_id` (`r_l_id`),
  CONSTRAINT `ratings_ibfk_1` FOREIGN KEY (`r_s_id`) REFERENCES `STUDENTS` (`s_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `ratings_ibfk_2` FOREIGN KEY (`r_l_id`) REFERENCES `LECTURES` (`l_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `RATINGS`
--

LOCK TABLES `RATINGS` WRITE;
/*!40000 ALTER TABLE `RATINGS` DISABLE KEYS */;
INSERT INTO `RATINGS` VALUES (1,'2012313382','CSE3007-41_201709',5.00,5.00,5.00,5.00,5.00,5.00,'후회없는 최고의 강의 !!!!'),(2,'2012313383','CSE3007-41_201709',5.00,5.00,5.00,5.00,5.00,5.00,'정말 마음에 드는 강의입니다 !'),(3,'2012313383','SWE3024-44_201709',1.00,2.00,3.00,1.00,2.00,1.80,'듣지마세요 최악입니다 .......'),(4,'2012313383','SWE3024-41_201709',5.00,5.00,5.00,5.00,5.00,5.00,'언제나 열정적인 강의 감사합니다 !'),(5,'2017313383','CSE3007-42_201703',3.00,4.00,3.00,5.00,4.00,3.80,'수업 어려우니 단단히 마음의 준비를 ..');
/*!40000 ALTER TABLE `RATINGS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Students`
--

DROP TABLE IF EXISTS `Students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Students` (
  `s_id` varchar(12) NOT NULL,
  `s_d_id` int(11) DEFAULT NULL,
  `s_m_id` int(11) DEFAULT NULL,
  `username` varchar(14) DEFAULT NULL,
  `s_email` varchar(40) DEFAULT NULL,
  `since_y` int(11) DEFAULT NULL,
  PRIMARY KEY (`s_id`),
  UNIQUE KEY `username` (`username`),
  KEY `s_d_id` (`s_d_id`),
  KEY `s_m_id` (`s_m_id`),
  CONSTRAINT `students_ibfk_1` FOREIGN KEY (`s_d_id`) REFERENCES `Departments` (`d_id`),
  CONSTRAINT `students_ibfk_2` FOREIGN KEY (`s_m_id`) REFERENCES `Majors` (`m_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Students`
--

LOCK TABLES `Students` WRITE;
/*!40000 ALTER TABLE `Students` DISABLE KEYS */;
INSERT INTO `Students` VALUES ('2012313380',1,2,'show6985','show1296@naver.com',2012),('2012313382',1,2,'show12966','show12966@gmail.com',2012),('2012313383',1,1,'show1296','show1296@gmail.com',2012),('2012313384',1,2,'abcd5678','show1296.us@gmail.com',2013),('2012313385',2,1,'abcd9012','show1296.uk@gmail.com',2014),('2012313386',2,2,'abcd9033','show1296.ca@gmail.com',2015),('2016232431',1,2,'show6969','rheoi@gmail.com',2016),('2016374837',1,2,'abcdefg','abcdefg@gmail.com',2016),('2017313383',1,2,'show7774','show7774@gmail.com',2017);
/*!40000 ALTER TABLE `Students` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_group`
--

DROP TABLE IF EXISTS `auth_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_group` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(80) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_group`
--

LOCK TABLES `auth_group` WRITE;
/*!40000 ALTER TABLE `auth_group` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_group_permissions`
--

DROP TABLE IF EXISTS `auth_group_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_group_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group_id` int(11) NOT NULL,
  `permission_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_group_permissions_group_id_permission_id_0cd325b0_uniq` (`group_id`,`permission_id`),
  KEY `auth_group_permissio_permission_id_84c5c92e_fk_auth_perm` (`permission_id`),
  CONSTRAINT `auth_group_permissio_permission_id_84c5c92e_fk_auth_perm` FOREIGN KEY (`permission_id`) REFERENCES `auth_permission` (`id`),
  CONSTRAINT `auth_group_permissions_group_id_b120cbf9_fk_auth_group_id` FOREIGN KEY (`group_id`) REFERENCES `auth_group` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_group_permissions`
--

LOCK TABLES `auth_group_permissions` WRITE;
/*!40000 ALTER TABLE `auth_group_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_group_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_permission`
--

DROP TABLE IF EXISTS `auth_permission`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_permission` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `content_type_id` int(11) NOT NULL,
  `codename` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_permission_content_type_id_codename_01ab375a_uniq` (`content_type_id`,`codename`),
  CONSTRAINT `auth_permission_content_type_id_2f476e4b_fk_django_co` FOREIGN KEY (`content_type_id`) REFERENCES `django_content_type` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=115 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_permission`
--

LOCK TABLES `auth_permission` WRITE;
/*!40000 ALTER TABLE `auth_permission` DISABLE KEYS */;
INSERT INTO `auth_permission` VALUES (1,'Can add log entry',1,'add_logentry'),(2,'Can change log entry',1,'change_logentry'),(3,'Can delete log entry',1,'delete_logentry'),(4,'Can add permission',2,'add_permission'),(5,'Can change permission',2,'change_permission'),(6,'Can delete permission',2,'delete_permission'),(7,'Can add group',3,'add_group'),(8,'Can change group',3,'change_group'),(9,'Can delete group',3,'delete_group'),(10,'Can add user',4,'add_user'),(11,'Can change user',4,'change_user'),(12,'Can delete user',4,'delete_user'),(13,'Can add content type',5,'add_contenttype'),(14,'Can change content type',5,'change_contenttype'),(15,'Can delete content type',5,'delete_contenttype'),(16,'Can add session',6,'add_session'),(17,'Can change session',6,'change_session'),(18,'Can delete session',6,'delete_session'),(19,'Can add auth group',7,'add_authgroup'),(20,'Can change auth group',7,'change_authgroup'),(21,'Can delete auth group',7,'delete_authgroup'),(22,'Can add auth group permissions',8,'add_authgrouppermissions'),(23,'Can change auth group permissions',8,'change_authgrouppermissions'),(24,'Can delete auth group permissions',8,'delete_authgrouppermissions'),(25,'Can add auth permission',9,'add_authpermission'),(26,'Can change auth permission',9,'change_authpermission'),(27,'Can delete auth permission',9,'delete_authpermission'),(28,'Can add auth user',10,'add_authuser'),(29,'Can change auth user',10,'change_authuser'),(30,'Can delete auth user',10,'delete_authuser'),(31,'Can add auth user groups',11,'add_authusergroups'),(32,'Can change auth user groups',11,'change_authusergroups'),(33,'Can delete auth user groups',11,'delete_authusergroups'),(34,'Can add auth user user permissions',12,'add_authuseruserpermissions'),(35,'Can change auth user user permissions',12,'change_authuseruserpermissions'),(36,'Can delete auth user user permissions',12,'delete_authuseruserpermissions'),(37,'Can add departments',13,'add_departments'),(38,'Can change departments',13,'change_departments'),(39,'Can delete departments',13,'delete_departments'),(40,'Can add django admin log',14,'add_djangoadminlog'),(41,'Can change django admin log',14,'change_djangoadminlog'),(42,'Can delete django admin log',14,'delete_djangoadminlog'),(43,'Can add django content type',15,'add_djangocontenttype'),(44,'Can change django content type',15,'change_djangocontenttype'),(45,'Can delete django content type',15,'delete_djangocontenttype'),(46,'Can add django migrations',16,'add_djangomigrations'),(47,'Can change django migrations',16,'change_djangomigrations'),(48,'Can delete django migrations',16,'delete_djangomigrations'),(49,'Can add django session',17,'add_djangosession'),(50,'Can change django session',17,'change_djangosession'),(51,'Can delete django session',17,'delete_djangosession'),(52,'Can add lectures',18,'add_lectures'),(53,'Can change lectures',18,'change_lectures'),(54,'Can delete lectures',18,'delete_lectures'),(55,'Can add majors',19,'add_majors'),(56,'Can change majors',19,'change_majors'),(57,'Can delete majors',19,'delete_majors'),(58,'Can add professors',20,'add_professors'),(59,'Can change professors',20,'change_professors'),(60,'Can delete professors',20,'delete_professors'),(61,'Can add ratings',21,'add_ratings'),(62,'Can change ratings',21,'change_ratings'),(63,'Can delete ratings',21,'delete_ratings'),(64,'Can add students',22,'add_students'),(65,'Can change students',22,'change_students'),(66,'Can delete students',22,'delete_students'),(67,'Can add auth group',23,'add_authgroup'),(68,'Can change auth group',23,'change_authgroup'),(69,'Can delete auth group',23,'delete_authgroup'),(70,'Can add auth group permissions',24,'add_authgrouppermissions'),(71,'Can change auth group permissions',24,'change_authgrouppermissions'),(72,'Can delete auth group permissions',24,'delete_authgrouppermissions'),(73,'Can add auth permission',25,'add_authpermission'),(74,'Can change auth permission',25,'change_authpermission'),(75,'Can delete auth permission',25,'delete_authpermission'),(76,'Can add auth user',26,'add_authuser'),(77,'Can change auth user',26,'change_authuser'),(78,'Can delete auth user',26,'delete_authuser'),(79,'Can add auth user groups',27,'add_authusergroups'),(80,'Can change auth user groups',27,'change_authusergroups'),(81,'Can delete auth user groups',27,'delete_authusergroups'),(82,'Can add auth user user permissions',28,'add_authuseruserpermissions'),(83,'Can change auth user user permissions',28,'change_authuseruserpermissions'),(84,'Can delete auth user user permissions',28,'delete_authuseruserpermissions'),(85,'Can add departments',29,'add_departments'),(86,'Can change departments',29,'change_departments'),(87,'Can delete departments',29,'delete_departments'),(88,'Can add django admin log',30,'add_djangoadminlog'),(89,'Can change django admin log',30,'change_djangoadminlog'),(90,'Can delete django admin log',30,'delete_djangoadminlog'),(91,'Can add django content type',31,'add_djangocontenttype'),(92,'Can change django content type',31,'change_djangocontenttype'),(93,'Can delete django content type',31,'delete_djangocontenttype'),(94,'Can add django migrations',32,'add_djangomigrations'),(95,'Can change django migrations',32,'change_djangomigrations'),(96,'Can delete django migrations',32,'delete_djangomigrations'),(97,'Can add django session',33,'add_djangosession'),(98,'Can change django session',33,'change_djangosession'),(99,'Can delete django session',33,'delete_djangosession'),(100,'Can add lectures',34,'add_lectures'),(101,'Can change lectures',34,'change_lectures'),(102,'Can delete lectures',34,'delete_lectures'),(103,'Can add majors',35,'add_majors'),(104,'Can change majors',35,'change_majors'),(105,'Can delete majors',35,'delete_majors'),(106,'Can add professors',36,'add_professors'),(107,'Can change professors',36,'change_professors'),(108,'Can delete professors',36,'delete_professors'),(109,'Can add ratings',37,'add_ratings'),(110,'Can change ratings',37,'change_ratings'),(111,'Can delete ratings',37,'delete_ratings'),(112,'Can add students',38,'add_students'),(113,'Can change students',38,'change_students'),(114,'Can delete students',38,'delete_students');
/*!40000 ALTER TABLE `auth_permission` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_user`
--

DROP TABLE IF EXISTS `auth_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `password` varchar(128) NOT NULL,
  `last_login` datetime(6) DEFAULT NULL,
  `is_superuser` tinyint(1) NOT NULL,
  `username` varchar(150) NOT NULL,
  `first_name` varchar(30) NOT NULL,
  `last_name` varchar(150) NOT NULL,
  `email` varchar(254) NOT NULL,
  `is_staff` tinyint(1) NOT NULL,
  `is_active` tinyint(1) NOT NULL,
  `date_joined` datetime(6) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user`
--

LOCK TABLES `auth_user` WRITE;
/*!40000 ALTER TABLE `auth_user` DISABLE KEYS */;
INSERT INTO `auth_user` VALUES (1,'pbkdf2_sha256$100000$UQmPTzaAiAgD$+1DKthYxCyiXKD+1nAab2jsF24UzaFWWj9c0OdETOwA=','2017-12-26 16:56:03.083613',1,'show1296','','','show1296.kr@gmail.com',1,1,'2017-12-23 15:08:08.000000'),(2,'pbkdf2_sha256$100000$GPHKlmb5i9a1$LKY3J2lVjmNmc1V3FMqbGqFzEuBEa/jHngCt1eTbb+w=',NULL,0,'abcd5678','','','',0,1,'2017-12-24 14:11:39.077205'),(3,'pbkdf2_sha256$100000$S0rzTFFrdAiu$LxzH5x/p9AgOf8R6L5LuA3owkwUU0HwI/DJ2prkYnp0=',NULL,0,'abcd9012','','','',0,1,'2017-12-24 14:11:50.059334'),(4,'pbkdf2_sha256$100000$RuYX4qIjgqHe$65/OZSvnHLyol1WYeVRlbNObxHKlQgzM63M96OYk0iY=',NULL,0,'abcd9033','','','',0,1,'2017-12-24 14:12:03.488763'),(7,'pbkdf2_sha256$100000$NFdO8YVKAft2$mw9AuhlDZwhakehKJdiM9u7R549QFyv7+CUypSBwjqs=',NULL,0,'abcdefg','','','abcdefg@gmail.com',0,1,'2017-12-25 15:00:30.394699'),(9,'pbkdf2_sha256$100000$0VVEaxnRyacV$uz2kz13jq3LNcmaqz7YtfhOAyukLoeuKS0ppvIfE++I=','2017-12-25 18:47:17.149239',0,'show6969','','','rheoi@gmail.com',0,1,'2017-12-25 18:47:09.068178'),(12,'pbkdf2_sha256$100000$nywrG5hX1XAh$Kil/nbuHaqSVAiXEkvLlNF8Pmu1DkOQX/78MNXiaFjg=',NULL,0,'show6985','','','show1296@naver.com',0,1,'2017-12-26 05:22:20.357627'),(13,'pbkdf2_sha256$100000$YYkzc6NNsqMQ$6qfzQTFTfc+i2H6MlB/s5C2+VAOKzARE7scBR+G8slo=','2017-12-26 13:41:51.279317',0,'show12966','','','show12966@gmail.com',0,1,'2017-12-26 13:27:56.987609'),(14,'pbkdf2_sha256$100000$DCgZ7aLdYCPA$JXMnj3EaEeo2p4OsMamHc6LNcIKIU95eSauvpDkHnFU=','2017-12-26 16:56:48.223220',0,'show7774','','','show7774@gmail.com',0,1,'2017-12-26 16:56:41.124822');
/*!40000 ALTER TABLE `auth_user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_user_groups`
--

DROP TABLE IF EXISTS `auth_user_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_user_groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `group_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_user_groups_user_id_group_id_94350c0c_uniq` (`user_id`,`group_id`),
  KEY `auth_user_groups_group_id_97559544_fk_auth_group_id` (`group_id`),
  CONSTRAINT `auth_user_groups_group_id_97559544_fk_auth_group_id` FOREIGN KEY (`group_id`) REFERENCES `auth_group` (`id`),
  CONSTRAINT `auth_user_groups_user_id_6a12ed8b_fk_auth_user_id` FOREIGN KEY (`user_id`) REFERENCES `auth_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user_groups`
--

LOCK TABLES `auth_user_groups` WRITE;
/*!40000 ALTER TABLE `auth_user_groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_user_groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_user_user_permissions`
--

DROP TABLE IF EXISTS `auth_user_user_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_user_user_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `permission_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_user_user_permissions_user_id_permission_id_14a6b632_uniq` (`user_id`,`permission_id`),
  KEY `auth_user_user_permi_permission_id_1fbb5f2c_fk_auth_perm` (`permission_id`),
  CONSTRAINT `auth_user_user_permi_permission_id_1fbb5f2c_fk_auth_perm` FOREIGN KEY (`permission_id`) REFERENCES `auth_permission` (`id`),
  CONSTRAINT `auth_user_user_permissions_user_id_a95ead1b_fk_auth_user_id` FOREIGN KEY (`user_id`) REFERENCES `auth_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user_user_permissions`
--

LOCK TABLES `auth_user_user_permissions` WRITE;
/*!40000 ALTER TABLE `auth_user_user_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_user_user_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_admin_log`
--

DROP TABLE IF EXISTS `django_admin_log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_admin_log` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `action_time` datetime(6) NOT NULL,
  `object_id` longtext,
  `object_repr` varchar(200) NOT NULL,
  `action_flag` smallint(5) unsigned NOT NULL,
  `change_message` longtext NOT NULL,
  `content_type_id` int(11) DEFAULT NULL,
  `user_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `django_admin_log_content_type_id_c4bce8eb_fk_django_co` (`content_type_id`),
  KEY `django_admin_log_user_id_c564eba6_fk_auth_user_id` (`user_id`),
  CONSTRAINT `django_admin_log_content_type_id_c4bce8eb_fk_django_co` FOREIGN KEY (`content_type_id`) REFERENCES `django_content_type` (`id`),
  CONSTRAINT `django_admin_log_user_id_c564eba6_fk_auth_user_id` FOREIGN KEY (`user_id`) REFERENCES `auth_user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_admin_log`
--

LOCK TABLES `django_admin_log` WRITE;
/*!40000 ALTER TABLE `django_admin_log` DISABLE KEYS */;
INSERT INTO `django_admin_log` VALUES (1,'2017-12-24 10:40:37.179785','1','show1296.kr@gmail.com',2,'[{\"changed\": {\"fields\": [\"username\"]}}]',4,1),(2,'2017-12-24 14:09:59.144487','1','show1296',2,'[{\"changed\": {\"fields\": [\"username\"]}}]',4,1),(3,'2017-12-24 14:11:39.200407','2','abcd5678',1,'[{\"added\": {}}]',4,1),(4,'2017-12-24 14:11:50.182291','3','abcd9012',1,'[{\"added\": {}}]',4,1),(5,'2017-12-24 14:12:03.615648','4','abcd9033',1,'[{\"added\": {}}]',4,1),(6,'2017-12-24 15:55:07.459776','5','show6985',3,'',4,1),(7,'2017-12-26 05:15:34.338817','6','show6985',3,'',4,1),(8,'2017-12-26 05:21:39.532119','11','show6985',3,'',4,1);
/*!40000 ALTER TABLE `django_admin_log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_content_type`
--

DROP TABLE IF EXISTS `django_content_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_content_type` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app_label` varchar(100) NOT NULL,
  `model` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `django_content_type_app_label_model_76bd3d3b_uniq` (`app_label`,`model`)
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_content_type`
--

LOCK TABLES `django_content_type` WRITE;
/*!40000 ALTER TABLE `django_content_type` DISABLE KEYS */;
INSERT INTO `django_content_type` VALUES (1,'admin','logentry'),(3,'auth','group'),(2,'auth','permission'),(4,'auth','user'),(5,'contenttypes','contenttype'),(23,'mainpage','authgroup'),(24,'mainpage','authgrouppermissions'),(25,'mainpage','authpermission'),(26,'mainpage','authuser'),(27,'mainpage','authusergroups'),(28,'mainpage','authuseruserpermissions'),(29,'mainpage','departments'),(30,'mainpage','djangoadminlog'),(31,'mainpage','djangocontenttype'),(32,'mainpage','djangomigrations'),(33,'mainpage','djangosession'),(34,'mainpage','lectures'),(35,'mainpage','majors'),(36,'mainpage','professors'),(37,'mainpage','ratings'),(38,'mainpage','students'),(7,'search','authgroup'),(8,'search','authgrouppermissions'),(9,'search','authpermission'),(10,'search','authuser'),(11,'search','authusergroups'),(12,'search','authuseruserpermissions'),(13,'search','departments'),(14,'search','djangoadminlog'),(15,'search','djangocontenttype'),(16,'search','djangomigrations'),(17,'search','djangosession'),(18,'search','lectures'),(19,'search','majors'),(20,'search','professors'),(21,'search','ratings'),(22,'search','students'),(6,'sessions','session');
/*!40000 ALTER TABLE `django_content_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_migrations`
--

DROP TABLE IF EXISTS `django_migrations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_migrations` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `applied` datetime(6) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_migrations`
--

LOCK TABLES `django_migrations` WRITE;
/*!40000 ALTER TABLE `django_migrations` DISABLE KEYS */;
INSERT INTO `django_migrations` VALUES (1,'contenttypes','0001_initial','2017-12-23 14:22:07.009818'),(2,'auth','0001_initial','2017-12-23 14:22:07.507839'),(3,'admin','0001_initial','2017-12-23 14:22:07.601684'),(4,'admin','0002_logentry_remove_auto_add','2017-12-23 14:22:07.646384'),(5,'contenttypes','0002_remove_content_type_name','2017-12-23 14:22:07.715761'),(6,'auth','0002_alter_permission_name_max_length','2017-12-23 14:22:07.773561'),(7,'auth','0003_alter_user_email_max_length','2017-12-23 14:22:07.835982'),(8,'auth','0004_alter_user_username_opts','2017-12-23 14:22:07.848551'),(9,'auth','0005_alter_user_last_login_null','2017-12-23 14:22:07.881853'),(10,'auth','0006_require_contenttypes_0002','2017-12-23 14:22:07.885088'),(11,'auth','0007_alter_validators_add_error_messages','2017-12-23 14:22:07.899058'),(12,'auth','0008_alter_user_username_max_length','2017-12-23 14:22:07.931575'),(13,'sessions','0001_initial','2017-12-23 14:22:07.971073'),(14,'auth','0009_alter_user_last_name_max_length','2017-12-23 14:52:51.196434'),(15,'search','0001_initial','2017-12-23 17:07:54.693413'),(16,'mainpage','0001_initial','2017-12-24 14:06:21.707956');
/*!40000 ALTER TABLE `django_migrations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_session`
--

DROP TABLE IF EXISTS `django_session`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_session` (
  `session_key` varchar(40) NOT NULL,
  `session_data` longtext NOT NULL,
  `expire_date` datetime(6) NOT NULL,
  PRIMARY KEY (`session_key`),
  KEY `django_session_expire_date_a5c62663` (`expire_date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_session`
--

LOCK TABLES `django_session` WRITE;
/*!40000 ALTER TABLE `django_session` DISABLE KEYS */;
INSERT INTO `django_session` VALUES ('64jvpptv4yy5niyf7rzutg87kuxxhx54','ODljOTZiYTY1MzE1Y2U2ZDAyY2Y5NzUwZTI2NDExYzlhMDMyMWEzNDp7Il9hdXRoX3VzZXJfaWQiOiIxNCIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImRqYW5nby5jb250cmliLmF1dGguYmFja2VuZHMuTW9kZWxCYWNrZW5kIiwiX2F1dGhfdXNlcl9oYXNoIjoiMjA4Y2U2M2NlMGUwNGMxMWRkNjU0ZWIzNjYwMzRjZWQyNDllMWE2YiJ9','2018-01-09 16:56:48.228662');
/*!40000 ALTER TABLE `django_session` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-12-27  2:09:04
