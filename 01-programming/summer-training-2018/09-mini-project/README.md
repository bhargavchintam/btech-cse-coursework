# Contact Book - mini project

The mini project I made at the end of the camp. It ties together the web track and the node track — a Bootstrap page on the front, an Express server at the back, and plain fetch calls in between. Contacts are kept in memory (no database, we hadn't done MySQL properly yet).

## What it does
- Add a contact (name, phone, email)
- See all contacts in a table
- Delete a contact

## Run it
```sh
cd 09-mini-project
npm install
npm start
```
Then open http://localhost:3000 in the browser.

## Files
- `index.html` — the page (Bootstrap 4.1 form + table)
- `style.css` — a little styling
- `app.js` — front end, calls the server with `fetch`
- `server.js` — Express backend, GET/POST/DELETE on `/contacts`
- `package.json` — express and body-parser

## What I would add later
- Save contacts to a file or database so they don't vanish on restart
- Edit a contact, not just add and delete
- Validate the phone and email properly
