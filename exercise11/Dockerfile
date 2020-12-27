FROM ubuntu:16.04

WORKDIR /mydir

RUN apt-get update && apt-get install -y curl git 

RUN curl -sL https://deb.nodesource.com/setup_10.x | bash
RUN apt-get install -y nodejs

RUN git clone https://github.com/docker-hy/backend-example-docker.git

RUN cd  backend-example-docker && npm install

WORKDIR backend-example-docker 

ENTRYPOINT ["/usr/bin/npm", "start"]


# Commands used

# touch logs.txt
# docker build -t backend .
# docker run -it -p 3000:8000 -v $(pwd)/logs.txt:/mydir/backend-example-docker/logs.txt backend
