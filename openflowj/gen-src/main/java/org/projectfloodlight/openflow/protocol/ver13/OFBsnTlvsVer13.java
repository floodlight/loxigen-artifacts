// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_factory_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import java.util.Set;
import java.util.List;


public class OFBsnTlvsVer13 implements OFBsnTlvs {
    public final static OFBsnTlvsVer13 INSTANCE = new OFBsnTlvsVer13();




    public OFBsnTlvActorKey.Builder buildActorKey() {
        return new OFBsnTlvActorKeyVer13.Builder();
    }
    public OFBsnTlvActorKey actorKey(int value) {
        return new OFBsnTlvActorKeyVer13(
                value
                    );
    }

    public OFBsnTlvActorPortNum.Builder buildActorPortNum() {
        return new OFBsnTlvActorPortNumVer13.Builder();
    }
    public OFBsnTlvActorPortNum actorPortNum(int value) {
        return new OFBsnTlvActorPortNumVer13(
                value
                    );
    }

    public OFBsnTlvActorPortPriority.Builder buildActorPortPriority() {
        return new OFBsnTlvActorPortPriorityVer13.Builder();
    }
    public OFBsnTlvActorPortPriority actorPortPriority(int value) {
        return new OFBsnTlvActorPortPriorityVer13(
                value
                    );
    }

    public OFBsnTlvActorState.Builder buildActorState() {
        return new OFBsnTlvActorStateVer13.Builder();
    }
    public OFBsnTlvActorState actorState(Set<OFBsnLacpState> value) {
        return new OFBsnTlvActorStateVer13(
                value
                    );
    }

    public OFBsnTlvActorSystemMac.Builder buildActorSystemMac() {
        return new OFBsnTlvActorSystemMacVer13.Builder();
    }
    public OFBsnTlvActorSystemMac actorSystemMac(MacAddress value) {
        return new OFBsnTlvActorSystemMacVer13(
                value
                    );
    }

    public OFBsnTlvActorSystemPriority.Builder buildActorSystemPriority() {
        return new OFBsnTlvActorSystemPriorityVer13.Builder();
    }
    public OFBsnTlvActorSystemPriority actorSystemPriority(int value) {
        return new OFBsnTlvActorSystemPriorityVer13(
                value
                    );
    }

    public OFBsnTlvBroadcastQueryTimeout.Builder buildBroadcastQueryTimeout() {
        return new OFBsnTlvBroadcastQueryTimeoutVer13.Builder();
    }
    public OFBsnTlvBroadcastQueryTimeout broadcastQueryTimeout(long value) {
        return new OFBsnTlvBroadcastQueryTimeoutVer13(
                value
                    );
    }

    public OFBsnTlvBucket.Builder buildBucket() {
        return new OFBsnTlvBucketVer13.Builder();
    }
    public OFBsnTlvBucket bucket(List<OFBsnTlv> value) {
        return new OFBsnTlvBucketVer13(
                value
                    );
    }

    public OFBsnTlvCircuitId.Builder buildCircuitId() {
        return new OFBsnTlvCircuitIdVer13.Builder();
    }
    public OFBsnTlvCircuitId circuitId(byte[] value) {
        return new OFBsnTlvCircuitIdVer13(
                value
                    );
    }

    public OFBsnTlvConvergenceStatus.Builder buildConvergenceStatus() {
        return new OFBsnTlvConvergenceStatusVer13.Builder();
    }
    public OFBsnTlvConvergenceStatus convergenceStatus(short value) {
        return new OFBsnTlvConvergenceStatusVer13(
                value
                    );
    }

    public OFBsnTlvCrcEnabled.Builder buildCrcEnabled() {
        return new OFBsnTlvCrcEnabledVer13.Builder();
    }
    public OFBsnTlvCrcEnabled crcEnabled(short value) {
        return new OFBsnTlvCrcEnabledVer13(
                value
                    );
    }

    public OFBsnTlvData.Builder buildData() {
        return new OFBsnTlvDataVer13.Builder();
    }
    public OFBsnTlvData data(byte[] value) {
        return new OFBsnTlvDataVer13(
                value
                    );
    }

    public OFBsnTlvEthDst.Builder buildEthDst() {
        return new OFBsnTlvEthDstVer13.Builder();
    }
    public OFBsnTlvEthDst ethDst(MacAddress value) {
        return new OFBsnTlvEthDstVer13(
                value
                    );
    }

    public OFBsnTlvEthSrc.Builder buildEthSrc() {
        return new OFBsnTlvEthSrcVer13.Builder();
    }
    public OFBsnTlvEthSrc ethSrc(MacAddress value) {
        return new OFBsnTlvEthSrcVer13(
                value
                    );
    }

    public OFBsnTlvExternalGatewayIp.Builder buildExternalGatewayIp() {
        return new OFBsnTlvExternalGatewayIpVer13.Builder();
    }
    public OFBsnTlvExternalGatewayIp externalGatewayIp(IPv4Address value) {
        return new OFBsnTlvExternalGatewayIpVer13(
                value
                    );
    }

    public OFBsnTlvExternalGatewayMac.Builder buildExternalGatewayMac() {
        return new OFBsnTlvExternalGatewayMacVer13.Builder();
    }
    public OFBsnTlvExternalGatewayMac externalGatewayMac(MacAddress value) {
        return new OFBsnTlvExternalGatewayMacVer13(
                value
                    );
    }

    public OFBsnTlvExternalIp.Builder buildExternalIp() {
        return new OFBsnTlvExternalIpVer13.Builder();
    }
    public OFBsnTlvExternalIp externalIp(IPv4Address value) {
        return new OFBsnTlvExternalIpVer13(
                value
                    );
    }

    public OFBsnTlvExternalMac.Builder buildExternalMac() {
        return new OFBsnTlvExternalMacVer13.Builder();
    }
    public OFBsnTlvExternalMac externalMac(MacAddress value) {
        return new OFBsnTlvExternalMacVer13(
                value
                    );
    }

    public OFBsnTlvExternalNetmask.Builder buildExternalNetmask() {
        return new OFBsnTlvExternalNetmaskVer13.Builder();
    }
    public OFBsnTlvExternalNetmask externalNetmask(IPv4Address value) {
        return new OFBsnTlvExternalNetmaskVer13(
                value
                    );
    }

    public OFBsnTlvHeaderSize.Builder buildHeaderSize() {
        return new OFBsnTlvHeaderSizeVer13.Builder();
    }
    public OFBsnTlvHeaderSize headerSize(long value) {
        return new OFBsnTlvHeaderSizeVer13(
                value
                    );
    }

    public OFBsnTlvIcmpCode.Builder buildIcmpCode() {
        return new OFBsnTlvIcmpCodeVer13.Builder();
    }
    public OFBsnTlvIcmpCode icmpCode(short value) {
        return new OFBsnTlvIcmpCodeVer13(
                value
                    );
    }

    public OFBsnTlvIcmpId.Builder buildIcmpId() {
        return new OFBsnTlvIcmpIdVer13.Builder();
    }
    public OFBsnTlvIcmpId icmpId(int value) {
        return new OFBsnTlvIcmpIdVer13(
                value
                    );
    }

    public OFBsnTlvIcmpType.Builder buildIcmpType() {
        return new OFBsnTlvIcmpTypeVer13.Builder();
    }
    public OFBsnTlvIcmpType icmpType(short value) {
        return new OFBsnTlvIcmpTypeVer13(
                value
                    );
    }

    public OFBsnTlvIdleNotification idleNotification() {
        return OFBsnTlvIdleNotificationVer13.INSTANCE;
    }

    public OFBsnTlvIdleTime.Builder buildIdleTime() {
        return new OFBsnTlvIdleTimeVer13.Builder();
    }
    public OFBsnTlvIdleTime idleTime(U64 value) {
        return new OFBsnTlvIdleTimeVer13(
                value
                    );
    }

    public OFBsnTlvIdleTimeout.Builder buildIdleTimeout() {
        return new OFBsnTlvIdleTimeoutVer13.Builder();
    }
    public OFBsnTlvIdleTimeout idleTimeout(long value) {
        return new OFBsnTlvIdleTimeoutVer13(
                value
                    );
    }

    public OFBsnTlvIgmpSnooping igmpSnooping() {
        return OFBsnTlvIgmpSnoopingVer13.INSTANCE;
    }

    public OFBsnTlvInternalGatewayMac.Builder buildInternalGatewayMac() {
        return new OFBsnTlvInternalGatewayMacVer13.Builder();
    }
    public OFBsnTlvInternalGatewayMac internalGatewayMac(MacAddress value) {
        return new OFBsnTlvInternalGatewayMacVer13(
                value
                    );
    }

    public OFBsnTlvInternalMac.Builder buildInternalMac() {
        return new OFBsnTlvInternalMacVer13.Builder();
    }
    public OFBsnTlvInternalMac internalMac(MacAddress value) {
        return new OFBsnTlvInternalMacVer13(
                value
                    );
    }

    public OFBsnTlvInterval.Builder buildInterval() {
        return new OFBsnTlvIntervalVer13.Builder();
    }
    public OFBsnTlvInterval interval(long value) {
        return new OFBsnTlvIntervalVer13(
                value
                    );
    }

    public OFBsnTlvIpProto.Builder buildIpProto() {
        return new OFBsnTlvIpProtoVer13.Builder();
    }
    public OFBsnTlvIpProto ipProto(short value) {
        return new OFBsnTlvIpProtoVer13(
                value
                    );
    }

    public OFBsnTlvIpv4.Builder buildIpv4() {
        return new OFBsnTlvIpv4Ver13.Builder();
    }
    public OFBsnTlvIpv4 ipv4(IPv4Address value) {
        return new OFBsnTlvIpv4Ver13(
                value
                    );
    }

    public OFBsnTlvIpv4Dst.Builder buildIpv4Dst() {
        return new OFBsnTlvIpv4DstVer13.Builder();
    }
    public OFBsnTlvIpv4Dst ipv4Dst(IPv4Address value) {
        return new OFBsnTlvIpv4DstVer13(
                value
                    );
    }

    public OFBsnTlvIpv4Netmask.Builder buildIpv4Netmask() {
        return new OFBsnTlvIpv4NetmaskVer13.Builder();
    }
    public OFBsnTlvIpv4Netmask ipv4Netmask(IPv4Address value) {
        return new OFBsnTlvIpv4NetmaskVer13(
                value
                    );
    }

    public OFBsnTlvIpv4Src.Builder buildIpv4Src() {
        return new OFBsnTlvIpv4SrcVer13.Builder();
    }
    public OFBsnTlvIpv4Src ipv4Src(IPv4Address value) {
        return new OFBsnTlvIpv4SrcVer13(
                value
                    );
    }

    public OFBsnTlvL2MulticastLookup l2MulticastLookup() {
        return OFBsnTlvL2MulticastLookupVer13.INSTANCE;
    }

    public OFBsnTlvMac.Builder buildMac() {
        return new OFBsnTlvMacVer13.Builder();
    }
    public OFBsnTlvMac mac(MacAddress value) {
        return new OFBsnTlvMacVer13(
                value
                    );
    }

    public OFBsnTlvMacMask.Builder buildMacMask() {
        return new OFBsnTlvMacMaskVer13.Builder();
    }
    public OFBsnTlvMacMask macMask(MacAddress value) {
        return new OFBsnTlvMacMaskVer13(
                value
                    );
    }

    public OFBsnTlvMissPackets.Builder buildMissPackets() {
        return new OFBsnTlvMissPacketsVer13.Builder();
    }
    public OFBsnTlvMissPackets missPackets(U64 value) {
        return new OFBsnTlvMissPacketsVer13(
                value
                    );
    }

    public OFBsnTlvMplsControlWord.Builder buildMplsControlWord() {
        return new OFBsnTlvMplsControlWordVer13.Builder();
    }
    public OFBsnTlvMplsControlWord mplsControlWord(short value) {
        return new OFBsnTlvMplsControlWordVer13(
                value
                    );
    }

    public OFBsnTlvMplsLabel.Builder buildMplsLabel() {
        return new OFBsnTlvMplsLabelVer13.Builder();
    }
    public OFBsnTlvMplsLabel mplsLabel(long value) {
        return new OFBsnTlvMplsLabelVer13(
                value
                    );
    }

    public OFBsnTlvMplsSequenced.Builder buildMplsSequenced() {
        return new OFBsnTlvMplsSequencedVer13.Builder();
    }
    public OFBsnTlvMplsSequenced mplsSequenced(short value) {
        return new OFBsnTlvMplsSequencedVer13(
                value
                    );
    }

    public OFBsnTlvName.Builder buildName() {
        return new OFBsnTlvNameVer13.Builder();
    }
    public OFBsnTlvName name(byte[] value) {
        return new OFBsnTlvNameVer13(
                value
                    );
    }

    public OFBsnTlvPartnerKey.Builder buildPartnerKey() {
        return new OFBsnTlvPartnerKeyVer13.Builder();
    }
    public OFBsnTlvPartnerKey partnerKey(int value) {
        return new OFBsnTlvPartnerKeyVer13(
                value
                    );
    }

    public OFBsnTlvPartnerPortNum.Builder buildPartnerPortNum() {
        return new OFBsnTlvPartnerPortNumVer13.Builder();
    }
    public OFBsnTlvPartnerPortNum partnerPortNum(int value) {
        return new OFBsnTlvPartnerPortNumVer13(
                value
                    );
    }

    public OFBsnTlvPartnerPortPriority.Builder buildPartnerPortPriority() {
        return new OFBsnTlvPartnerPortPriorityVer13.Builder();
    }
    public OFBsnTlvPartnerPortPriority partnerPortPriority(int value) {
        return new OFBsnTlvPartnerPortPriorityVer13(
                value
                    );
    }

    public OFBsnTlvPartnerState.Builder buildPartnerState() {
        return new OFBsnTlvPartnerStateVer13.Builder();
    }
    public OFBsnTlvPartnerState partnerState(Set<OFBsnLacpState> value) {
        return new OFBsnTlvPartnerStateVer13(
                value
                    );
    }

    public OFBsnTlvPartnerSystemMac.Builder buildPartnerSystemMac() {
        return new OFBsnTlvPartnerSystemMacVer13.Builder();
    }
    public OFBsnTlvPartnerSystemMac partnerSystemMac(MacAddress value) {
        return new OFBsnTlvPartnerSystemMacVer13(
                value
                    );
    }

    public OFBsnTlvPartnerSystemPriority.Builder buildPartnerSystemPriority() {
        return new OFBsnTlvPartnerSystemPriorityVer13.Builder();
    }
    public OFBsnTlvPartnerSystemPriority partnerSystemPriority(int value) {
        return new OFBsnTlvPartnerSystemPriorityVer13(
                value
                    );
    }

    public OFBsnTlvPort.Builder buildPort() {
        return new OFBsnTlvPortVer13.Builder();
    }
    public OFBsnTlvPort port(OFPort value) {
        return new OFBsnTlvPortVer13(
                value
                    );
    }

    public OFBsnTlvPriority.Builder buildPriority() {
        return new OFBsnTlvPriorityVer13.Builder();
    }
    public OFBsnTlvPriority priority(long value) {
        return new OFBsnTlvPriorityVer13(
                value
                    );
    }

    public OFBsnTlvQueueId.Builder buildQueueId() {
        return new OFBsnTlvQueueIdVer13.Builder();
    }
    public OFBsnTlvQueueId queueId(long value) {
        return new OFBsnTlvQueueIdVer13(
                value
                    );
    }

    public OFBsnTlvQueueWeight.Builder buildQueueWeight() {
        return new OFBsnTlvQueueWeightVer13.Builder();
    }
    public OFBsnTlvQueueWeight queueWeight(long value) {
        return new OFBsnTlvQueueWeightVer13(
                value
                    );
    }

    public OFBsnTlvReference.Builder buildReference() {
        return new OFBsnTlvReferenceVer13.Builder();
    }
    public OFBsnTlvReference reference(int tableId, List<OFBsnTlv> key) {
        return new OFBsnTlvReferenceVer13(
                tableId,
                      key
                    );
    }

    public OFBsnTlvReplyPackets.Builder buildReplyPackets() {
        return new OFBsnTlvReplyPacketsVer13.Builder();
    }
    public OFBsnTlvReplyPackets replyPackets(U64 value) {
        return new OFBsnTlvReplyPacketsVer13(
                value
                    );
    }

    public OFBsnTlvRequestPackets.Builder buildRequestPackets() {
        return new OFBsnTlvRequestPacketsVer13.Builder();
    }
    public OFBsnTlvRequestPackets requestPackets(U64 value) {
        return new OFBsnTlvRequestPacketsVer13(
                value
                    );
    }

    public OFBsnTlvRxBytes.Builder buildRxBytes() {
        return new OFBsnTlvRxBytesVer13.Builder();
    }
    public OFBsnTlvRxBytes rxBytes(U64 value) {
        return new OFBsnTlvRxBytesVer13(
                value
                    );
    }

    public OFBsnTlvRxPackets.Builder buildRxPackets() {
        return new OFBsnTlvRxPacketsVer13.Builder();
    }
    public OFBsnTlvRxPackets rxPackets(U64 value) {
        return new OFBsnTlvRxPacketsVer13(
                value
                    );
    }

    public OFBsnTlvSamplingRate.Builder buildSamplingRate() {
        return new OFBsnTlvSamplingRateVer13.Builder();
    }
    public OFBsnTlvSamplingRate samplingRate(long value) {
        return new OFBsnTlvSamplingRateVer13(
                value
                    );
    }

    public OFBsnTlvSetLoopbackMode setLoopbackMode() {
        return OFBsnTlvSetLoopbackModeVer13.INSTANCE;
    }

    public OFBsnTlvStripMplsL2OnIngress stripMplsL2OnIngress() {
        return OFBsnTlvStripMplsL2OnIngressVer13.INSTANCE;
    }

    public OFBsnTlvStripMplsL3OnIngress stripMplsL3OnIngress() {
        return OFBsnTlvStripMplsL3OnIngressVer13.INSTANCE;
    }

    public OFBsnTlvStripVlanOnEgress stripVlanOnEgress() {
        return OFBsnTlvStripVlanOnEgressVer13.INSTANCE;
    }

    public OFBsnTlvSubAgentId.Builder buildSubAgentId() {
        return new OFBsnTlvSubAgentIdVer13.Builder();
    }
    public OFBsnTlvSubAgentId subAgentId(long value) {
        return new OFBsnTlvSubAgentIdVer13(
                value
                    );
    }

    public OFBsnTlvTcpDst.Builder buildTcpDst() {
        return new OFBsnTlvTcpDstVer13.Builder();
    }
    public OFBsnTlvTcpDst tcpDst(int value) {
        return new OFBsnTlvTcpDstVer13(
                value
                    );
    }

    public OFBsnTlvTcpSrc.Builder buildTcpSrc() {
        return new OFBsnTlvTcpSrcVer13.Builder();
    }
    public OFBsnTlvTcpSrc tcpSrc(int value) {
        return new OFBsnTlvTcpSrcVer13(
                value
                    );
    }

    public OFBsnTlvTxBytes.Builder buildTxBytes() {
        return new OFBsnTlvTxBytesVer13.Builder();
    }
    public OFBsnTlvTxBytes txBytes(U64 value) {
        return new OFBsnTlvTxBytesVer13(
                value
                    );
    }

    public OFBsnTlvTxPackets.Builder buildTxPackets() {
        return new OFBsnTlvTxPacketsVer13.Builder();
    }
    public OFBsnTlvTxPackets txPackets(U64 value) {
        return new OFBsnTlvTxPacketsVer13(
                value
                    );
    }

    public OFBsnTlvUdfAnchor.Builder buildUdfAnchor() {
        return new OFBsnTlvUdfAnchorVer13.Builder();
    }
    public OFBsnTlvUdfAnchor udfAnchor(OFBsnUdfAnchor value) {
        return new OFBsnTlvUdfAnchorVer13(
                value
                    );
    }

    public OFBsnTlvUdfId.Builder buildUdfId() {
        return new OFBsnTlvUdfIdVer13.Builder();
    }
    public OFBsnTlvUdfId udfId(int value) {
        return new OFBsnTlvUdfIdVer13(
                value
                    );
    }

    public OFBsnTlvUdfLength.Builder buildUdfLength() {
        return new OFBsnTlvUdfLengthVer13.Builder();
    }
    public OFBsnTlvUdfLength udfLength(int value) {
        return new OFBsnTlvUdfLengthVer13(
                value
                    );
    }

    public OFBsnTlvUdfOffset.Builder buildUdfOffset() {
        return new OFBsnTlvUdfOffsetVer13.Builder();
    }
    public OFBsnTlvUdfOffset udfOffset(int value) {
        return new OFBsnTlvUdfOffsetVer13(
                value
                    );
    }

    public OFBsnTlvUdpDst.Builder buildUdpDst() {
        return new OFBsnTlvUdpDstVer13.Builder();
    }
    public OFBsnTlvUdpDst udpDst(int value) {
        return new OFBsnTlvUdpDstVer13(
                value
                    );
    }

    public OFBsnTlvUdpSrc.Builder buildUdpSrc() {
        return new OFBsnTlvUdpSrcVer13.Builder();
    }
    public OFBsnTlvUdpSrc udpSrc(int value) {
        return new OFBsnTlvUdpSrcVer13(
                value
                    );
    }

    public OFBsnTlvUnicastQueryTimeout.Builder buildUnicastQueryTimeout() {
        return new OFBsnTlvUnicastQueryTimeoutVer13.Builder();
    }
    public OFBsnTlvUnicastQueryTimeout unicastQueryTimeout(long value) {
        return new OFBsnTlvUnicastQueryTimeoutVer13(
                value
                    );
    }

    public OFBsnTlvVlanPcp.Builder buildVlanPcp() {
        return new OFBsnTlvVlanPcpVer13.Builder();
    }
    public OFBsnTlvVlanPcp vlanPcp(short value) {
        return new OFBsnTlvVlanPcpVer13(
                value
                    );
    }

    public OFBsnTlvVlanVid.Builder buildVlanVid() {
        return new OFBsnTlvVlanVidVer13.Builder();
    }
    public OFBsnTlvVlanVid vlanVid(VlanVid value) {
        return new OFBsnTlvVlanVidVer13(
                value
                    );
    }

    public OFBsnTlvVlanVidMask.Builder buildVlanVidMask() {
        return new OFBsnTlvVlanVidMaskVer13.Builder();
    }
    public OFBsnTlvVlanVidMask vlanVidMask(int value) {
        return new OFBsnTlvVlanVidMaskVer13(
                value
                    );
    }

    public OFBsnTlvVrf.Builder buildVrf() {
        return new OFBsnTlvVrfVer13.Builder();
    }
    public OFBsnTlvVrf vrf(long value) {
        return new OFBsnTlvVrfVer13(
                value
                    );
    }

    public OFMessageReader<OFBsnTlv> getReader() {
        return OFBsnTlvVer13.READER;
    }


    public OFVersion getVersion() {
            return OFVersion.OF_13;
    }
}
