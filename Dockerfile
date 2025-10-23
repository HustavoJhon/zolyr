FROM gcc:latest
WORKDIR /app
COPY src/ /app/src/
RUN g++ /app/src/main.cpp -o finproc
CMD ["./finproc"]

