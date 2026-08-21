import React from 'react'

function Students() {
  let stud = [
    {
        id : 370,
        name : "Shreena",
        course : "CSE"
    },
    {
        id : 317,
        name : "Priyal",
        course : "CSE"
    },
    {
        id : 321,
        name : "Swasti",
        course : "CSE"
    }
  ]
  return (
    <>
        <h2>Student List</h2>
        <table border={1}>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Name</th>
                    <th>Course</th>
                </tr>
            </thead>
            <tbody>
                {stud.map((st)=>(
                <tr>
                    <td>{st.id}</td>
                    <td>{st.name}</td>
                    <td>{st.course}</td>
                </tr>
                ))}
            </tbody>
        </table>
    </>
  )
}

export default Students