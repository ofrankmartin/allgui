# syntax=docker/dockerfile:1

# Define the base image to be used.
FROM debian:bullseye

# No user interaction.
ARG DEBIAN_FRONTEND=noninteractive

# Override user name at build, if buil-arg not passed, will create user named `solobakeuser` user.
ARG DOCKER_USER=builderman
ARG DOCKER_GID=1000
ARG DOCKER_UID=1000

# Set to use bash instead of dash.
SHELL ["/bin/bash", "-c"]

# Create a user for the image builder.
RUN addgroup --gid $DOCKER_GID $DOCKER_USER && adduser --uid $DOCKER_UID --ingroup $DOCKER_USER $DOCKER_USER

# Set the working directory for that user
WORKDIR /home/$DOCKER_USER/

# Install basic dependencies.
RUN apt-get update && apt-get install -y \
    sudo \
    apt-transport-https \
    curl \
    doxygen \
    git \
    libssl-dev \
    ninja-build \
    openssh-client \
    rsync \
    wget \
    libsdl2-dev \
    cmake \
    g++

# Create folder for ssh keys. 
RUN mkdir -p -m 0600 ~/.ssh

# Add GitHub public key to known hosts.
RUN ssh-keyscan github.com >> ~/.ssh/known_hosts

# Create folder where projects should be checked-out or mounted.
RUN mkdir -p /opt/projects/allgui

# Update Opt folder permissions and its sub-folders.
RUN chown -hR $DOCKER_USER:$DOCKER_USER /opt/

# Add user to dialout group.
RUN usermod -aG dialout $DOCKER_USER

# Add user to sudoers list.
RUN usermod -aG sudo $DOCKER_USER && echo "$DOCKER_USER ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Remove unnecessary apt cache.
RUN apt-get autoremove -y && rm -rf /var/lib/apt/lists/*

# Change from root to $DOCKER_USER.
USER $DOCKER_USER

# Add environment variables.
RUN echo -e "\nexport PROJ_DIR=/opt/projects" >> ~/.bashrc
RUN echo -e "\nalias ll='ls -lah'" >> ~/.bashrc