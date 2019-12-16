# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 12:31:40 by asablayr          #+#    #+#              #
#    Updated: 2019/12/15 14:19:32 by asablayr         ###   ########.fr        #
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
COPY	query.php var/www/wordpress

RUN	rm var/www/wordpress/wp-config-sample.php && \
	ln -s /etc/nginx/sites-available/monsite.com etc/nginx/sites-enabled/ && \
	useradd -d /home/monsite -m monsite && \
	mkdir -p /var/run/php && \
	chmod 777 /var/run/php 

RUN	apt install -y python3-acme python3-certbot python3-mock python3-openssl python3-pkg-resources python3-pyparsing python3-zope.interface && \
	apt install python3-certbot-nginx
#	certbot --nginx -d monsite.com

COPY	hosts.txt etc/

ENTRYPOINT	service nginx start && \
			service mysql start && \
			php-fpm7.3			&& \
			mariadb -u root	-p="" --execute="CREATE DATABASE wordpress; GRANT ALL ON wordpress.* TO 'Antoine'@'localhost' IDENTIFIED BY 'password'; FLUSH PRIVILEGES;"	&& \
			bin/bash
