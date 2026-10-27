# Lab 6 - Multi-container app with Docker Compose

## Aim
Use Docker Compose to run a multi-container application (WordPress web + MySQL db) defined in a single compose file.

## Tools / Environment
- Docker CE 19.03
- Docker Compose 1.25 (file version 3.8)
- images: `wordpress:php7.4`, `mysql:5.7`
- compose file (see `Lab06_docker-compose.yml`)

## Procedure
1. Install docker-compose: `sudo apt-get install -y docker-compose`. Check: `docker-compose --version`.
2. Create the compose file with two services, `web` and `db`. `web` depends on `db`, db data kept in a named volume:

```yaml
version: "3.8"
services:
  web:
    image: wordpress:php7.4
    ports:
      - "8080:80"
    environment:
      WORDPRESS_DB_HOST: db:3306
      WORDPRESS_DB_USER: wpuser
      WORDPRESS_DB_PASSWORD: wppass
      WORDPRESS_DB_NAME: wpdb
    depends_on:
      - db
  db:
    image: mysql:5.7
    environment:
      MYSQL_DATABASE: wpdb
      MYSQL_USER: wpuser
      MYSQL_PASSWORD: wppass
      MYSQL_ROOT_PASSWORD: rootpass
    volumes:
      - db_data:/var/lib/mysql
volumes:
  db_data:
```

3. Start the stack (detached):

```
docker-compose up -d
```

4. Check running services: `docker-compose ps`.
5. Open `http://localhost:8080` - WordPress setup page.
6. Tear down (keep volume): `docker-compose down`. To also remove volume: `docker-compose down -v`.

## Observation / Output
- `docker-compose up -d` pulls both images, creates a default network, starts `db` then `web`.
- `docker-compose ps` shows both containers `Up`, web on 0.0.0.0:8080->80.
- WordPress install wizard loads at localhost:8080, connects to the mysql db over the compose network.

## Result
Multi-container WordPress + MySQL app deployed and linked together using Docker Compose.
