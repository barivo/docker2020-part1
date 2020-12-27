# 1.1 Getting Started

CONTAINER ID IMAGE COMMAND CREATED STATUS PORTS NAMES
9149e36f19e0 nginx:latest "/docker-entrypoint.…" 2 minutes ago Exited (0) 57 seconds ago elastic_turing
faff635ed0da nginx:latest "/docker-entrypoint.…" 2 minutes ago Exited (0) 48 seconds ago crazy_ptolemy
02fe17e5b366 nginx:latest "/docker-entrypoint.…" 2 minutes ago Up 2 minutes 80/tcp laughing_moser
cb52a2283c4a jakousa/dwk-app1 "docker-entrypoint.s…" 47 minutes ago Exited (0) 47 minutes ago keen_vaughan
b4114352bde3 rancher/k3d-proxy:v3.1.2 "/bin/sh -c nginx-pr…" 55 minutes ago Exited (143) 47 minutes ago k3d-k3s-default-serverlb
403c6aeec17f rancher/k3s:latest "/bin/k3s agent" 55 minutes ago Exited (1) 47 minutes ago k3d-k3s-default-agent-1
257d327fbd5f rancher/k3s:latest "/bin/k3s agent" 55 minutes ago Exited (1) 47 minutes ago k3d-k3s-default-agent-0
61808a7a26f2 rancher/k3s:latest "/bin/k3s server --t…" 55 minutes ago Exited (1) 47 minutes ago k3d-k3s-default-server-0

# 1.2 Cleanup

CONTAINER ID IMAGE COMMAND CREATED STATUS PORTS NAMES
`docker images`
REPOSITORY TAG IMAGE ID CREATED SIZE

# 1.3 Hello Docker Hub

You found the correct password. Secret message is:
"This is the secret message"

# 1.4

docker run -d --name bashexec devopsdockeruh/exec_bash_exercise
docker exec -it bashexec bash

Secret message is:
"Docker is easy"

# 1.5

docker run -it --rm --name webcurl ubuntu:16.04 sh -c 'apt-get update; apt-get install curl; echo "Input website:"; read website; echo "Searching.."; sleep 1; curl http://$website;'

# 1.6

FROM devopsdockeruh/overwrite_cmd_exercise
CMD ["-c 10"]

docker run -it docker-clock

# 1.7

FROM ubuntu:16.04

WORKDIR /mydir
RUN apt-get update && apt-get install -y curl

COPY curler.sh .
RUN chmod +x curler.sh
RUN echo pwd

#to use <command> without a shell use the "exec form" which parses a JSON array:
CMD ["/bin/bash", "./curler.sh"]

#or execute the shell directly, as default parmameters to ENTRYPOINT
#CMD ["sh", "-c", "./curler.sh"]

#or use the shell form
#CMD ./curler.sh

docker build -t curler .
docker run -it curler

# 1.8

touch logs.txt

docker run -d -v (pwd)/logs.txt:/usr/app/logs.txt devopsdockeruh/first_volume_exercise

docker stop determined_germain

Secret message is:
"Volume bind mount is easy"

# 1.9

docker-2020 docker run -d -p 3000:80 devopsdockeruh/ports_exercise

#1b04c21c2ccecd52c9728306c69c80e6b8b3b6c07bc28971b8ccab57c0918405

docker-2020 docker stop 1b
