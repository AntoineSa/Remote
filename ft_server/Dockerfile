# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 12:31:40 by asablayr          #+#    #+#              #
#    Updated: 2019/12/17 16:43:08 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update && \
	apt install -y nginx wget php-cli php-mysql php-curl php-gd php-intl php-fpm && \
	apt install -y mariadb-server && \
	wget https://wordpress.org/latest.tar.gz && \
	mv latest.tar.gz var/www/ && \
	cd var/www/ && tar -xzvf latest.tar.gz && rm -rf latest.tar.gz

COPY	monsite.com etc/nginx/sites-available/ 
COPY	wp-config.php var/www/wordpress

RUN	rm var/www/wordpress/wp-config-sample.php && \
	ln -s /etc/nginx/sites-available/monsite.com etc/nginx/sites-enabled/ && \
	useradd -d /home/monsite -m monsite && \
	mkdir -p /var/run/php && \
	chmod 777 /var/run/php 

RUN	apt install -y php-mbstring php-gettext && \
	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz && \
	tar xvf phpMyAdmin-4.9.2-all-languages.tar.gz && \
	mv phpMyAdmin-4.9.2-all-languages/ /usr/share/phpmyadmin && rm -rf phpMyAdmin-4.9.2-all-languages.tar.gz && \
	mkdir -p var/lib/phpmyadmin && \
	mkdir -p var/lib/phpmyadmin/tmp && \
	chmod 777 var/lib/phpmyadmin && \
	chmod 777 var/lib/phpmyadmin/tmp

COPY	config.inc.php usr/share/phpmyadmin/config.inc.php
COPY	nginx-selfsigned.key etc/ssl/private/nginxself-signed.key
COPY	nginx-selfsigned.crt etc/ssl/certs/nginx-selfsigned.crt

ENTRYPOINT	service nginx start && \
			service mysql start && \
			php-fpm7.3			&& \
			mariadb < /usr/share/phpmyadmin/sql/create_tables.sql && \
			mariadb -u root	-p="" --execute="CREATE DATABASE wordpress; GRANT ALL ON wordpress.* TO 'Antoine'@'localhost' IDENTIFIED BY 'password'; FLUSH PRIVILEGES; GRANT ALL ON phpmyadmin.* TO 'Antoine'@'localhost' IDENTIFIED BY 'password'; FLUSH PRIVILEGES;"	&& \
			bin/bash
