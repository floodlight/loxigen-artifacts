// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import io.netty.buffer.ByteBuf;
import java.util.Set;

abstract class OFBsnHeaderVer15 {
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 16;


    public final static OFBsnHeaderVer15.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFBsnHeader> {
        @Override
        public OFBsnHeader readFrom(ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 6
            byte version = bb.readByte();
            if(version != (byte) 0x6)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_15(6), got="+version);
            // fixed value property type == 4
            byte type = bb.readByte();
            if(type != (byte) 0x4)
                throw new OFParseError("Wrong type: Expected=OFType.EXPERIMENTER(4), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            U32.f(bb.readInt());
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            int subtype = bb.readInt();
            bb.readerIndex(start);
            switch(subtype) {
               case 0x16:
                   // discriminator value 0x16L=0x16L for class OFBsnBwClearDataReplyVer15
                   return OFBsnBwClearDataReplyVer15.READER.readFrom(bb);
               case 0x15:
                   // discriminator value 0x15L=0x15L for class OFBsnBwClearDataRequestVer15
                   return OFBsnBwClearDataRequestVer15.READER.readFrom(bb);
               case 0x14:
                   // discriminator value 0x14L=0x14L for class OFBsnBwEnableGetReplyVer15
                   return OFBsnBwEnableGetReplyVer15.READER.readFrom(bb);
               case 0x13:
                   // discriminator value 0x13L=0x13L for class OFBsnBwEnableGetRequestVer15
                   return OFBsnBwEnableGetRequestVer15.READER.readFrom(bb);
               case 0x17:
                   // discriminator value 0x17L=0x17L for class OFBsnBwEnableSetReplyVer15
                   return OFBsnBwEnableSetReplyVer15.READER.readFrom(bb);
               case 0x12:
                   // discriminator value 0x12L=0x12L for class OFBsnBwEnableSetRequestVer15
                   return OFBsnBwEnableSetRequestVer15.READER.readFrom(bb);
               case 0xa:
                   // discriminator value 0xaL=0xaL for class OFBsnGetInterfacesReplyVer15
                   return OFBsnGetInterfacesReplyVer15.READER.readFrom(bb);
               case 0x9:
                   // discriminator value 0x9L=0x9L for class OFBsnGetInterfacesRequestVer15
                   return OFBsnGetInterfacesRequestVer15.READER.readFrom(bb);
               case 0x5:
                   // discriminator value 0x5L=0x5L for class OFBsnGetMirroringReplyVer15
                   return OFBsnGetMirroringReplyVer15.READER.readFrom(bb);
               case 0x4:
                   // discriminator value 0x4L=0x4L for class OFBsnGetMirroringRequestVer15
                   return OFBsnGetMirroringRequestVer15.READER.readFrom(bb);
               case 0x22:
                   // discriminator value 0x22L=0x22L for class OFBsnPduRxReplyVer15
                   return OFBsnPduRxReplyVer15.READER.readFrom(bb);
               case 0x21:
                   // discriminator value 0x21L=0x21L for class OFBsnPduRxRequestVer15
                   return OFBsnPduRxRequestVer15.READER.readFrom(bb);
               case 0x23:
                   // discriminator value 0x23L=0x23L for class OFBsnPduRxTimeoutVer15
                   return OFBsnPduRxTimeoutVer15.READER.readFrom(bb);
               case 0x20:
                   // discriminator value 0x20L=0x20L for class OFBsnPduTxReplyVer15
                   return OFBsnPduTxReplyVer15.READER.readFrom(bb);
               case 0x1f:
                   // discriminator value 0x1fL=0x1fL for class OFBsnPduTxRequestVer15
                   return OFBsnPduTxRequestVer15.READER.readFrom(bb);
               case 0x3:
                   // discriminator value 0x3L=0x3L for class OFBsnSetMirroringVer15
                   return OFBsnSetMirroringVer15.READER.readFrom(bb);
               case 0x19:
                   // discriminator value 0x19L=0x19L for class OFBsnSetPktinSuppressionReplyVer15
                   return OFBsnSetPktinSuppressionReplyVer15.READER.readFrom(bb);
               case 0xb:
                   // discriminator value 0xbL=0xbL for class OFBsnSetPktinSuppressionRequestVer15
                   return OFBsnSetPktinSuppressionRequestVer15.READER.readFrom(bb);
               case 0x10:
                   // discriminator value 0x10L=0x10L for class OFBsnVirtualPortCreateReplyVer15
                   return OFBsnVirtualPortCreateReplyVer15.READER.readFrom(bb);
               case 0xf:
                   // discriminator value 0xfL=0xfL for class OFBsnVirtualPortCreateRequestVer15
                   return OFBsnVirtualPortCreateRequestVer15.READER.readFrom(bb);
               case 0x1a:
                   // discriminator value 0x1aL=0x1aL for class OFBsnVirtualPortRemoveReplyVer15
                   return OFBsnVirtualPortRemoveReplyVer15.READER.readFrom(bb);
               case 0x11:
                   // discriminator value 0x11L=0x11L for class OFBsnVirtualPortRemoveRequestVer15
                   return OFBsnVirtualPortRemoveRequestVer15.READER.readFrom(bb);
               case 0x3c:
                   // discriminator value 0x3cL=0x3cL for class OFBsnArpIdleVer15
                   return OFBsnArpIdleVer15.READER.readFrom(bb);
               case 0x39:
                   // discriminator value 0x39L=0x39L for class OFBsnControllerConnectionsReplyVer15
                   return OFBsnControllerConnectionsReplyVer15.READER.readFrom(bb);
               case 0x38:
                   // discriminator value 0x38L=0x38L for class OFBsnControllerConnectionsRequestVer15
                   return OFBsnControllerConnectionsRequestVer15.READER.readFrom(bb);
               case 0x28:
                   // discriminator value 0x28L=0x28L for class OFBsnFlowIdleVer15
                   return OFBsnFlowIdleVer15.READER.readFrom(bb);
               case 0x27:
                   // discriminator value 0x27L=0x27L for class OFBsnFlowIdleEnableGetReplyVer15
                   return OFBsnFlowIdleEnableGetReplyVer15.READER.readFrom(bb);
               case 0x26:
                   // discriminator value 0x26L=0x26L for class OFBsnFlowIdleEnableGetRequestVer15
                   return OFBsnFlowIdleEnableGetRequestVer15.READER.readFrom(bb);
               case 0x25:
                   // discriminator value 0x25L=0x25L for class OFBsnFlowIdleEnableSetReplyVer15
                   return OFBsnFlowIdleEnableSetReplyVer15.READER.readFrom(bb);
               case 0x24:
                   // discriminator value 0x24L=0x24L for class OFBsnFlowIdleEnableSetRequestVer15
                   return OFBsnFlowIdleEnableSetRequestVer15.READER.readFrom(bb);
               case 0x31:
                   // discriminator value 0x31L=0x31L for class OFBsnGentableClearReplyVer15
                   return OFBsnGentableClearReplyVer15.READER.readFrom(bb);
               case 0x30:
                   // discriminator value 0x30L=0x30L for class OFBsnGentableClearRequestVer15
                   return OFBsnGentableClearRequestVer15.READER.readFrom(bb);
               case 0x2e:
                   // discriminator value 0x2eL=0x2eL for class OFBsnGentableEntryAddVer15
                   return OFBsnGentableEntryAddVer15.READER.readFrom(bb);
               case 0x2f:
                   // discriminator value 0x2fL=0x2fL for class OFBsnGentableEntryDeleteVer15
                   return OFBsnGentableEntryDeleteVer15.READER.readFrom(bb);
               case 0x32:
                   // discriminator value 0x32L=0x32L for class OFBsnGentableSetBucketsSizeVer15
                   return OFBsnGentableSetBucketsSizeVer15.READER.readFrom(bb);
               case 0x34:
                   // discriminator value 0x34L=0x34L for class OFBsnGetSwitchPipelineReplyVer15
                   return OFBsnGetSwitchPipelineReplyVer15.READER.readFrom(bb);
               case 0x33:
                   // discriminator value 0x33L=0x33L for class OFBsnGetSwitchPipelineRequestVer15
                   return OFBsnGetSwitchPipelineRequestVer15.READER.readFrom(bb);
               case 0x2b:
                   // discriminator value 0x2bL=0x2bL for class OFBsnLacpConvergenceNotifVer15
                   return OFBsnLacpConvergenceNotifVer15.READER.readFrom(bb);
               case 0x3f:
                   // discriminator value 0x3fL=0x3fL for class OFBsnLogVer15
                   return OFBsnLogVer15.READER.readFrom(bb);
               case 0x42:
                   // discriminator value 0x42L=0x42L for class OFBsnLuaCommandReplyVer15
                   return OFBsnLuaCommandReplyVer15.READER.readFrom(bb);
               case 0x41:
                   // discriminator value 0x41L=0x41L for class OFBsnLuaCommandRequestVer15
                   return OFBsnLuaCommandRequestVer15.READER.readFrom(bb);
               case 0x43:
                   // discriminator value 0x43L=0x43L for class OFBsnLuaNotificationVer15
                   return OFBsnLuaNotificationVer15.READER.readFrom(bb);
               case 0x40:
                   // discriminator value 0x40L=0x40L for class OFBsnLuaUploadVer15
                   return OFBsnLuaUploadVer15.READER.readFrom(bb);
               case 0x3b:
                   // discriminator value 0x3bL=0x3bL for class OFBsnSetAuxCxnsReplyVer15
                   return OFBsnSetAuxCxnsReplyVer15.READER.readFrom(bb);
               case 0x3a:
                   // discriminator value 0x3aL=0x3aL for class OFBsnSetAuxCxnsRequestVer15
                   return OFBsnSetAuxCxnsRequestVer15.READER.readFrom(bb);
               case 0x2a:
                   // discriminator value 0x2aL=0x2aL for class OFBsnSetLacpReplyVer15
                   return OFBsnSetLacpReplyVer15.READER.readFrom(bb);
               case 0x29:
                   // discriminator value 0x29L=0x29L for class OFBsnSetLacpRequestVer15
                   return OFBsnSetLacpRequestVer15.READER.readFrom(bb);
               case 0x36:
                   // discriminator value 0x36L=0x36L for class OFBsnSetSwitchPipelineReplyVer15
                   return OFBsnSetSwitchPipelineReplyVer15.READER.readFrom(bb);
               case 0x35:
                   // discriminator value 0x35L=0x35L for class OFBsnSetSwitchPipelineRequestVer15
                   return OFBsnSetSwitchPipelineRequestVer15.READER.readFrom(bb);
               case 0x3d:
                   // discriminator value 0x3dL=0x3dL for class OFBsnTableSetBucketsSizeVer15
                   return OFBsnTableSetBucketsSizeVer15.READER.readFrom(bb);
               case 0x2d:
                   // discriminator value 0x2dL=0x2dL for class OFBsnTimeReplyVer15
                   return OFBsnTimeReplyVer15.READER.readFrom(bb);
               case 0x2c:
                   // discriminator value 0x2cL=0x2cL for class OFBsnTimeRequestVer15
                   return OFBsnTimeRequestVer15.READER.readFrom(bb);
               case 0x46:
                   // discriminator value 0x46L=0x46L for class OFBsnVlanCounterClearVer15
                   return OFBsnVlanCounterClearVer15.READER.readFrom(bb);
               case 0x44:
                   // discriminator value 0x44L=0x44L for class OFBsnGenericAsyncVer15
                   return OFBsnGenericAsyncVer15.READER.readFrom(bb);
               case 0x47:
                   // discriminator value 0x47L=0x47L for class OFBsnGenericCommandVer15
                   return OFBsnGenericCommandVer15.READER.readFrom(bb);
               case 0x48:
                   // discriminator value 0x48L=0x48L for class OFBsnGenericCommandReplyVer15
                   return OFBsnGenericCommandReplyVer15.READER.readFrom(bb);
               case 0x45:
                   // discriminator value 0x45L=0x45L for class OFBsnTakeoverVer15
                   return OFBsnTakeoverVer15.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator subtype of class OFBsnHeaderVer15: " + subtype);
            }
        }
    }
}
