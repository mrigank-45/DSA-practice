// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Item {
    struct Product {
        uint256 productId;
        string name;
        uint256 price;
        // Add more product details as needed
    }

    uint256 public productCount;
    mapping(uint256 => Product) public products;

    // Event to emit when a new product is added
    event ProductAdded(uint256 productId, string name, uint256 price);

    // Function to add a new product
    function addProduct(string memory _name, uint256 _price) external {
        // Increment the productCount to get a unique product ID
        productCount++;

        // Create a new product instance
        Product memory newProduct = Product({
            productId: productCount,
            name: _name,
            price: _price
            // Add more product details as needed
        });

        // Store the new product in the mapping using its ID as the key
        products[productCount] = newProduct;

        // Emit an event to signal the addition of a new product
        emit ProductAdded(productCount, _name, _price);
    }

    // Function to add multiple products at once
    function addMultipleProducts(Product[] memory _products) external {
        for (uint256 i = 0; i < _products.length; i++) {
            // Increment the productCount to get a unique product ID
            productCount++;

            // Store the new product in the mapping using its ID as the key
            products[productCount] = _products[i];

            // Emit an event to signal the addition of a new product
            emit ProductAdded(
                productCount,
                _products[i].name,
                _products[i].price
            );
        }
    }

    function getProductById(
        uint256 _productId
    ) external view returns (Product memory) {
        return products[_productId];
    }
}
