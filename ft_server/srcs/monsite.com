server {
	server_name     monsite.com;
	return          301 http://www.monsite.com$request_uri;
}

server {
	# Port
	listen 80;
	listen 443 ssl http2 default_server;

	include snippets/self-signed.conf;
	include snippets/ssl-params.conf;

	# Hostname
	server_name 192.168.99.111;

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

	location /phpmyadmin {
               root /usr/share/;
               index index.php index.html index.htm;
               location ~ ^/phpmyadmin/(.+\.php)$ {
                       try_files $uri =404;
                       root /usr/share/;
                       fastcgi_pass unix:/run/php/php7.3-fpm.sock;
                       fastcgi_index index.php;
                       fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
                       include /etc/nginx/fastcgi_params;
               }
               location ~* ^/phpmyadmin/(.+\.(jpg|jpeg|gif|css|png|js|ico|html|xml|txt))$ {
                       root /usr/share/;
               }
        }
	location ~ /\.ht {
        deny all;
    }
}
