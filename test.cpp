require(
    userStakingAmount[msg.sender] <=
        IERC20(stakingToken).balanceOf(address(this)),
    "Not enough balance in contract");
// transfer
stakingToken.transfer(msg.sender, userStakingAmount[msg.sender]);
userStakingAmount[msg.sender] = 0;

require(
    rewards[msg.sender] <=
        IERC20(stakingToken).balanceOf(address(this)),
    "Not enough balance in contract");
rewardToken.transfer(msg.sender, rewards[msg.sender]);\
