// SPDX-License-Identifier: MIT

pragma solidity ^0.8;

contract BeCall {
    event Hint(string);

    fallback() external payable {
        emit Hint("function not found.");
    }

}

contract Caller {
    function call(address payable _addr) public {
        (bool success, bytes memory data) = _addr.call(
            abi.encodeWithSignature("test(uint)", 100)
        );
    }
}