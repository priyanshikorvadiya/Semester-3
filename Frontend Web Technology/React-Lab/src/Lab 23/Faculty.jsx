import { useState } from "react";
import React from "react";

function Faculty() {
  const [faculties, setFaculties] = useState([]);
  const [name, setName] = useState("");
  const [department, setDepartment] = useState("");
  const [editIndex, setEditIndex] = useState(-1);

  const saveData = () => {
    if (name.trim() === "" || department.trim() === "") {
      alert("Enter Data");
      return;
    }

    if (editIndex === -1) {
      setFaculties([...faculties, { name, department }]);
    } else {
      let updated = [...faculties];
      updated[editIndex] = { name, department };
      setFaculties(updated);
      setEditIndex(-1);
    }

    setName("");
    setDepartment("");
  };

  let editData = (index) => {
    setName(faculties[index].name);
    setDepartment(faculties[index].department);
    setEditIndex(index);
  };

  let deleteData = (index) => {
    let updated = faculties.filter((_, i) => i !== index);
    setFaculties(updated);

    if (editIndex === index) {
      setEditIndex(-1);
      setName("");
      setDepartment("");
    }
  };

  return (
    <>
      <h2>CRUD By Array For Faculties</h2>
      <input
        type="text"
        placeholder="Faculty Name"
        value={name}
        onChange={(e) => setName(e.target.value)}
      />
      <input
        type="text"
        placeholder="Department"
        value={department}
        onChange={(e) => setDepartment(e.target.value)}
      />
      <button onClick={saveData}>
        {editIndex === -1 ? "Add" : "Update"}
      </button>
      <br />
      <br />

      <table border="1" cellSpacing="2" cellPadding="5">
        <thead>
          <tr>
            <th>Faculty Name</th>
            <th>Department</th>
            <th>Action</th>
          </tr>
        </thead>
        <tbody>
          {faculties.map((item, index) => (
            <tr key={index}>
              <td>{item.name}</td>
              <td>{item.department}</td>
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

export default Faculty;