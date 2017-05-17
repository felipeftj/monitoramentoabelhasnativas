
-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tempo de Geração: 13/09/2016 às 15:40:44
-- Versão do Servidor: 10.0.20-MariaDB
-- Versão do PHP: 5.2.17

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Banco de Dados: `u629018256_db`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_data`
--

CREATE TABLE IF NOT EXISTS `tb_data` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `data` varchar(45) NOT NULL,
  `hora` varchar(45) NOT NULL,
  `t1` varchar(45) NOT NULL,
  `h1` varchar(45) NOT NULL,
  `t2` varchar(45) NOT NULL,
  `h2` varchar(45) NOT NULL,
  `t3` varchar(45) NOT NULL,
  `h3` varchar(45) NOT NULL,
  `t4` varchar(45) NOT NULL,
  `h4` varchar(45) NOT NULL,
  `t5` varchar(45) NOT NULL,
  `h5` varchar(45) NOT NULL,
  `t6` varchar(45) NOT NULL,
  `h6` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=46 ;

--
-- Extraindo dados da tabela `tb_data`
--

INSERT INTO `tb_data` (`id`, `data`, `hora`, `t1`, `h1`, `t2`, `h2`, `t3`, `h3`, `t4`, `h4`, `t5`, `h5`, `t6`, `h6`) VALUES
(1, '15/7/2016', '19:12:20', '24.3', '81.1', '23.0', '82.1', '24.1', '78.2', '25.7', '81.1', '24.6', '75.1', '22.4', '83.2'),
(2, '15/7/2016', '19:12:24', '24.3', '81.1', '23.0', '82.1', '24.1', '78.2', '25.7', '81.1', '24.6', '75.1', '22.4', '83.2');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;