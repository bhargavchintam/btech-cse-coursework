# 2-stage build: compile go binary, then run it on a small alpine image
FROM golang:1.15 AS build
WORKDIR /src
COPY go.mod .
COPY main.go .
RUN CGO_ENABLED=0 go build -o app main.go

FROM alpine:3.12
WORKDIR /app
COPY --from=build /src/app .
EXPOSE 8080
CMD ["./app"]
