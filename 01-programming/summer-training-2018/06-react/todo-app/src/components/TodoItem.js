import React from 'react';

function TodoItem(props) {
  return (
    <li className="todo-item">
      {props.text}
      <button onClick={() => props.onDelete(props.index)}>x</button>
    </li>
  );
}

export default TodoItem;
