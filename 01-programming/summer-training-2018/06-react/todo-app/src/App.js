import React, { Component } from 'react';
import './App.css';
import TodoItem from './components/TodoItem';

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      todos: ['learn react', 'finish java assignment'],
      text: ''
    };
    this.handleChange = this.handleChange.bind(this);
    this.addTodo = this.addTodo.bind(this);
    this.deleteTodo = this.deleteTodo.bind(this);
  }

  handleChange(e) {
    this.setState({ text: e.target.value });
  }

  addTodo() {
    if (this.state.text === '') {
      return;
    }
    const todos = this.state.todos.concat(this.state.text);
    this.setState({ todos: todos, text: '' });
  }

  deleteTodo(index) {
    const todos = this.state.todos.filter((t, i) => i !== index);
    this.setState({ todos: todos });
  }

  render() {
    return (
      <div className="app">
        <h1>My Todo List</h1>
        <div className="addbox">
          <input
            type="text"
            value={this.state.text}
            onChange={this.handleChange}
            placeholder="enter task"
          />
          <button onClick={this.addTodo}>Add</button>
        </div>
        <ul>
          {this.state.todos.map((todo, index) => (
            <TodoItem
              key={index}
              text={todo}
              index={index}
              onDelete={this.deleteTodo}
            />
          ))}
        </ul>
      </div>
    );
  }
}

export default App;
