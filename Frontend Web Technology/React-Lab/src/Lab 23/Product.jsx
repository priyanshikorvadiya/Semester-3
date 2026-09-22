import { useState } from "react";
import react from "react";

function Product() {
  const [products, setProducts] = useState([]);
  const [name, setName] = useState("");
  const [price, setPrice] = useState("");
  const [editIndex, setEditIndex] = useState(-1);

  const saveData = () => {
    if (name == " " || price == " ") {
      alert("Enter Data");
      return;
    }

    if (editIndex === -1) {
      setProducts([...products, { name, price }]);
    } else {
      let updated = [...products];
      updated[editIndex] = { name, price };
      setProducts(updated);
      setEditIndex(-1);
    }

    // let temp = [...products];
    // if (editIndex == -1) {
    //   temp.push({ name: name, price: price });
    // } else {
    //   temp[editIndex] = { name: name, price: price };
    //   setEditIndex(-1);
    // }

    setName("");
    setPrice("");
  };

  let editData = (index) => {
    setName(products[index].name);
    setPrice(products[index].price);
    setEditIndex(index);
  };

  let deleteData = (index) => {
    let updated = products.filter((_, i) => i !== index);
    setProducts(updated);

    if (editIndex === index) {
      setEditIndex(-1);
      setName("");
      setPrice("");
    }
  };

  return (
    <>
      <h2>CRUD By Array For Products</h2>
      <input
        type="text"
        placeholder="name"
        value={name}
        onChange={(e) => setName(e.target.value)}
      />
      <input
        type="text"
        placeholder="price"
        value={price}
        onChange={(e) => setPrice(e.target.value)}
      />
      <button onClick={saveData}>
        {" "}
        {editIndex === -1 ? "Add" : "Update"}{" "}
      </button>
      <br />
      <br />

      <table border="1" cellSpacing="2" cellPadding="5">
        <thead>
          <tr>
            <th>Name</th>
            <th>Price</th>
            <th>Action</th>
          </tr>
        </thead>
        <tbody>
          {products.map((item, index) => (
            <tr key={index}>
              <td>{item.name}</td>
              <td>{item.price}</td>
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

export default Product;