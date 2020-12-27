# 1.13

FROM openjdk:8
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN ./mvnw package
CMD java -jar ./target/docker-example-1.1.3.jar

docker build -t spring-example .
docker run -it -p 3000:8080 spring-example

# 1.14

FROM ruby:2.6.0
#throw errors if Gemfile has been modified since Gemfile.lock
RUN bundle config --global frozen 1
WORKDIR /usr/src/app
COPY Gemfile Gemfile.lock ./
RUN bundle install
COPY . .

RUN apt-get update; \
 apt-get install -y curl gnupg; \
 curl -sL https://deb.nodesource.com/setup_11.x | bash -; \
 apt-get install -y nodejs; \
 rm -rf /var/lib/apt/lists/\*

#ENV RAILS_ENV=production
RUN ./bin/rails db:migrate
RUN ./bin/rake assets:precompile
ENV RAILS_LOG_TO_STDOUT=true
#RUN ./bin/rails s -e production

CMD ["./bin/rails", "s"]

docker build -t rails-example .
docker run -it -p 3000:3000 rails-example

# 1.15

https://hub.docker.com/repository/docker/jay101/youtube-dl

# 1.16

#Go to https://www.heroku.com/ and create a new app there and install heroku CLI. You can find additional instructions from Deploy tab under Container Registry

heroku login
heroku auth:whoami
heroku container:login

docker tag devopsdockeruh/heroku-example registry.heroku.com/docker-part1/web

docker push registry.heroku.com/docker-part1/web

heroku container:login # may need to login again
heroku container:release web -a docker-part1

#Rails "New Press" app
https://docker-part1.herokuapp.com/

# 1.17

A C programming environment with a shared local folder "student0".
Files may be edited in the container or in the host. As some of
the binaries used for testing are ELF exectubles, only the container
may be used and not the OSX host.
Lastly, a local vimcr config is copied to the container directory.

FROM ubuntu:16.04
COPY ./student0 /home/student0
COPY .bashrc /root/.bashrc

RUN apt-get update && apt-get install -y curl git build-essential vim && \
 rm -rf /var/lib/apt/lists/\*

COPY vimrc /etc/vim/vimrc

WORKDIR /home/student0

CMD ["bash", "-l"]

#run with:
docker run -t -i -v $(pwd)/student0:/home/student0 cs162 /bin/bash)
