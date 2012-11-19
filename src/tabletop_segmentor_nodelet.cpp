/*********************************************************************
*
*  Copyright (c) 2012, Yujin Robot
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Yujin Robot nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/**
 * @author: Marcus Liebhardt, Yujin Robot
 * @date: 2012
 * @brief: ROS nodelet implementation of the tabletop segmentor
 */

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <tabletop_segmentor/tabletop_segmentation.h>


namespace tabletop_segmentor
{
  class TabletopSegmentorNodelet : public nodelet::Nodelet
  {
  public:
    virtual void onInit()
    {
      NODELET_DEBUG("Initializing nodelet...");
      segmentor_.reset(new TabletopSegmentor(this->getPrivateNodeHandle()));
    }
  private:
    boost::shared_ptr<TabletopSegmentor> segmentor_;
  };
}


PLUGINLIB_DECLARE_CLASS(tabletop_segmentor, TabletopSegmentorNodelet, tabletop_segmentor::TabletopSegmentorNodelet,
                        nodelet::Nodelet);
