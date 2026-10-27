# npm notes

npm init asks questions (name, version etc) and makes package.json.
package.json keeps the list of packages our project needs.

npm install express --save puts it in dependencies.
dependencies = needed to run the app (express, body-parser).
devDependencies = only for development (nodemon, we install with --save-dev).

node_modules folder is big, never upload it. anyone can run npm install
and get everything back from package.json.
