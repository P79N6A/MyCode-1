Page({
  data: {
    orderlist: [
      {
        time: 1000,
        id: 123745,
        goods: [
          {
            fruit_name: "苹果",
            fruit_weight: 2,
            fruit_price: 5,
            fruit_money: 10,
          },
          {
            fruit_name: "梨子",
            fruit_weight: 3,
            fruit_price: 6,
            fruit_money: 18,
          }
        ]
      },
      {
        time: 1856,
        id: 789456,
        goods: [
          {
            fruit_name: "西瓜",
            fruit_weight: 4,
            fruit_price: 5,
            fruit_money: 20,
          },
          {
            fruit_name: "荔枝",
            fruit_weight: 6,
            fruit_price: 6,
            fruit_money: 36,
          },
          {
            fruit_name: "西瓜",
            fruit_weight: 4,
            fruit_price: 5,
            fruit_money: 20,
          }
        ]
      }
    ]
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    /* wx.setNavigationBarTitle({
       title: "我的信息"
     })*/

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})