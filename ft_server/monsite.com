server {
	server_name     monsite.com;
	return          301 http://www.monsite.com$request_uri;
}

server {
	# Port
	listen 80;

	# Hostname
	server_name 192.168.99.106;

	# Logs (acces et erreurs)
	access_log /var/log/nginx/monsite.com.access.log;
	error_log /var/log/nginx/monsite.com.error.log;

	# Repertoire
	root /var/www/wordpress;
	index index.php index.html index.nginx-debian.html;

	# Fichier a executer par defaut (en ordre)
	index index.php index.html;

	location ~ \.php$ {
		include snippets/fastcgi-php.conf;
		fastcgi_pass unix:/run/php/php7.3-fpm.sock;
	}

	location ~ /\.ht {
        deny all;
    }
}
