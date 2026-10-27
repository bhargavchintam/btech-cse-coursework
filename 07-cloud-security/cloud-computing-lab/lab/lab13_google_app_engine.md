# Lab 13 - Deploy an app to Google App Engine

**Date:** 01-12-2020

## Aim

Deploy a small Python web app to Google App Engine (standard environment) with `gcloud app deploy`
and reach it on its appspot URL - a PaaS deploy where Google runs the server, you just ship code.

## Tools

- Google Cloud SDK (gcloud 319.0.0)
- A GCP project on the free trial
- App Engine standard, Python 3.8 runtime

## Procedure

1. Set up the SDK and pick the project:

   ```
   gcloud init
   gcloud config set project cloud-lab-2020
   ```

2. App files:

   `main.py`:

   ```python
   from flask import Flask
   app = Flask(__name__)

   @app.route("/")
   def home():
       return "hello from app engine\n"
   ```

   `requirements.txt`:

   ```
   Flask==1.1.2
   gunicorn==20.0.4
   ```

   `app.yaml` - this is the file that tells App Engine how to run it:

   ```yaml
   runtime: python38
   entrypoint: gunicorn -b :$PORT main:app

   handlers:
     - url: /.*
       script: auto
   ```

3. First time only, create the App Engine app and choose a region:

   ```
   gcloud app create --region=asia-south1
   ```

4. Deploy:

   ```
   gcloud app deploy
   ```

   It uploads the source, builds it and rolls out a version. Answer `Y` at the confirm prompt.

5. Open it and tail the logs:

   ```
   gcloud app browse
   gcloud app logs tail -s default
   ```

6. Deploy a change and it versions automatically; you can split traffic or roll back:

   ```
   gcloud app versions list
   ```

## Output

```
$ gcloud app deploy
Services to deploy:
  target project:        [cloud-lab-2020]
  target service:        [default]
  target url:            [https://cloud-lab-2020.el.r.appspot.com]

Do you want to continue (Y/n)?  Y
Beginning deployment of service [default]...
File upload done.
Updating service [default]...done.
Deployed service [default] to [https://cloud-lab-2020.el.r.appspot.com]

$ curl https://cloud-lab-2020.el.r.appspot.com/
hello from app engine
```

## Result

The app was deployed to App Engine with one command. There is no server to provision or patch -
`app.yaml` names the runtime and entrypoint and Google handles the rest, including scaling to zero
when idle. That is the PaaS trade-off versus the EC2 lab: less control over the machine, far less to
manage. Each `deploy` creates a new version, so rollback is just pointing traffic back.
