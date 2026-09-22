import { useState } from "react";
import React from "react";

function Student() {
  const [students, setStudents] = useState([]);
  const [rollNo, setRollNo] = useState("");
  const [name, setName] = useState("");
  const [editIndex, setEditIndex] = useState(-1);

  const saveData = () => {
    if (rollNo.trim() === "" || name.trim() === "") {
      alert("Enter Data");
      return;
    }

    if (editIndex === -1) {
      setStudents([...students, { rollNo, name }]);
    } else {
      let updated = [...students];
      updated[editIndex] = { rollNo, name };
      setStudents(updated);
      setEditIndex(-1);
    }

    setRollNo("");
    setName("");
  };

  let editData = (index) => {
    setRollNo(students[index].rollNo);
    setName(students[index].name);
    setEditIndex(index);
  };

  let deleteData = (index) => {
    let updated = students.filter((_, i) => i !== index);
    setStudents(updated);

    if (editIndex === index) {
      setEditIndex(-1);
      setRollNo("");
      setName("");
    }
  };

  return (
    <>
      <h2>CRUD By Array For Students</h2>
      <input
        type="text"
        placeholder="Roll No"
        value={rollNo}
        onChange={(e) => setRollNo(e.target.value)}
      />
      <input
        type="text"
        placeholder="Name"
        value={name}
        onChange={(e) => setName(e.target.value)}
      />
      <button onClick={saveData}>
        {editIndex === -1 ? "Add" : "Update"}
      </button>
      <br />
      <br />

      <table border="1" cellSpacing="2" cellPadding="5">
        <thead>
          <tr>
            <th>Roll No</th>
            <th>Name</th>
            <th>Action</th>
          </tr>
        </thead>
        <tbody>
          {students.map((item, index) => (
            <tr key={index}>
              <td>{item.rollNo}</td>
              <td>{item.name}</td>
              <td>
                <button onClick={() => editData(index)}>Edit</button>
                <button onClick={() => deleteData(index)}>Delete</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </>
  );
}

export default Student;