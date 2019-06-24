/* 
 * File:   h264depacketizer.h
 * Author: Sergio
 *
 * Created on 26 de enero de 2012, 9:46
 */

#ifndef H264DEPACKETIZER_H
#define	H264DEPACKETIZER_H
#include "rtp.h"
#include "video.h"

class H264Depacketizer : public RTPDepacketizer
{
public:
	H264Depacketizer();
	virtual ~H264Depacketizer();
	virtual void SetTimestamp(DWORD timestamp) override;
	virtual MediaFrame* AddPacket(const RTPPacket::shared& packet) override;
	virtual MediaFrame* AddPayload(const BYTE* payload,DWORD payload_len) override;
	virtual void ResetFrame() override;
	virtual DWORD GetTimestamp() override
	{
		return frame.GetTimeStamp();
	} 
private:
	VideoFrame frame;
	DWORD iniFragNALU;
};

#endif	/* H264DEPACKETIZER_H */

