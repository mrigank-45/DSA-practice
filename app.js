import React, { useState } from 'react';
import Web3 from 'web3';
import * as XLSX from 'xlsx'

export function App(props) {
  const [contractAddress, setContractAddress] = useState(
    'YOUR_CONTRACT_ADDRESS'
  );
  const [contractAbi, setContractAbi] = useState(""); // Replace with your contract ABI

  // on change states
  const [excelFile, setExcelFile] = useState(null);
  const [excelFileError, setExcelFileError] = useState(null);

  // submit
  const [excelData, setExcelData] = useState(null);
  // it will contain array of objects

  // handle File
  const fileType = ['application/vnd.ms-excel'];
  const handleFile = e => {
    let selectedFile = e.target.files[0];
    if (selectedFile) {
      // console.log(selectedFile.type);
      if (selectedFile && fileType.includes(selectedFile.type)) {
        let reader = new FileReader();
        reader.readAsArrayBuffer(selectedFile);
        reader.onload = e => {
          setExcelFileError(null);
          setExcelFile(e.target.result);
        };
      } else {
        setExcelFileError('Please select only excel file types');
        setExcelFile(null);
      }
    } else {
      console.log('plz select your file');
    }
  };

  // submit function
  const handleSubmit = e => {
    e.preventDefault();
    if (excelFile !== null) {
      const workbook = XLSX.read(excelFile, { type: 'buffer' });
      const worksheetName = workbook.SheetNames[0];
      const worksheet = workbook.Sheets[worksheetName];
      const data = XLSX.utils.sheet_to_json(worksheet);
       const dataArrayFormat = data.map(item => [
      item.productId,
      item.name,
      item.price,
    ]);

    console.log(dataArrayFormat);
    setExcelData(dataArrayFormat);
      // handleAddMultipleProducts();
    } else {
      setExcelData(null);
    }
  };

  const handleAddMultipleProducts = async () => {
    if (!window.ethereum) {
      alert('Please install MetaMask to use this feature.');
      return;
    }

    const web3 = new Web3(window.ethereum);
    try {
      // Get the user's Ethereum account
      const accounts = await window.ethereum.request({
        method: 'eth_requestAccounts',
      });
      const account = accounts[0];

      // Create a contract instance
      const contract = new web3.eth.Contract(contractAbi, contractAddress);

      // Call the smart contract function to add multiple products
      console.log(excelData);
      await contract.methods
        .addMultipleProducts(excelData)
        .send({ from: account });
      console.log('Products added successfully.');
    } catch (error) {
      console.error('Error adding products:', error);
    }
  };

  return (
    <div>
      <div className='form'>
        <form className='form-group' autoComplete='off' onSubmit={handleSubmit}>
          <label>
            <h5>Upload Excel file</h5>
          </label>
          <br></br>
          <input
            type='file'
            className='form-control'
            onChange={handleFile}
            required
          ></input>
          {excelFileError && (
            <div className='text-danger' style={{ marginTop: 5 + 'px' }}>
              {excelFileError}
            </div>
          )}
          <button
            type='submit'
            className='btn btn-success'
            style={{ marginTop: 5 + 'px' }}
          >
            Submit
          </button>
        </form>
      </div>
    </div>
  );
}
