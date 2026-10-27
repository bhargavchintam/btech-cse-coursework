// event emitter demo
var events = require('events');
var emitter = new events.EventEmitter();

emitter.on('greet', function(name) {
    console.log("hello " + name);
});

emitter.on('bye', function() {
    console.log("bye bye");
});

emitter.emit('greet', 'bhargav');
emitter.emit('greet', 'sir');
emitter.emit('bye');
