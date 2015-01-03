// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
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
import org.jboss.netty.buffer.ChannelBuffer;
import java.util.Set;

abstract class OFBsnHeaderVer13 {
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int MINIMUM_LENGTH = 16;


    public final static OFBsnHeaderVer13.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFBsnHeader> {
        @Override
        public OFBsnHeader readFrom(ChannelBuffer bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 4
            byte version = bb.readByte();
            if(version != (byte) 0x4)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_13(4), got="+version);
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
                   // discriminator value 0x16L=0x16L for class OFBsnBwClearDataReplyVer13
                   return OFBsnBwClearDataReplyVer13.READER.readFrom(bb);
               case 0x15:
                   // discriminator value 0x15L=0x15L for class OFBsnBwClearDataRequestVer13
                   return OFBsnBwClearDataRequestVer13.READER.readFrom(bb);
               case 0x14:
                   // discriminator value 0x14L=0x14L for class OFBsnBwEnableGetReplyVer13
                   return OFBsnBwEnableGetReplyVer13.READER.readFrom(bb);
               case 0x13:
                   // discriminator value 0x13L=0x13L for class OFBsnBwEnableGetRequestVer13
                   return OFBsnBwEnableGetRequestVer13.READER.readFrom(bb);
               case 0x17:
                   // discriminator value 0x17L=0x17L for class OFBsnBwEnableSetReplyVer13
                   return OFBsnBwEnableSetReplyVer13.READER.readFrom(bb);
               case 0x12:
                   // discriminator value 0x12L=0x12L for class OFBsnBwEnableSetRequestVer13
                   return OFBsnBwEnableSetRequestVer13.READER.readFrom(bb);
               case 0xa:
                   // discriminator value 0xaL=0xaL for class OFBsnGetInterfacesReplyVer13
                   return OFBsnGetInterfacesReplyVer13.READER.readFrom(bb);
               case 0x9:
                   // discriminator value 0x9L=0x9L for class OFBsnGetInterfacesRequestVer13
                   return OFBsnGetInterfacesRequestVer13.READER.readFrom(bb);
               case 0x5:
                   // discriminator value 0x5L=0x5L for class OFBsnGetMirroringReplyVer13
                   return OFBsnGetMirroringReplyVer13.READER.readFrom(bb);
               case 0x4:
                   // discriminator value 0x4L=0x4L for class OFBsnGetMirroringRequestVer13
                   return OFBsnGetMirroringRequestVer13.READER.readFrom(bb);
               case 0x22:
                   // discriminator value 0x22L=0x22L for class OFBsnPduRxReplyVer13
                   return OFBsnPduRxReplyVer13.READER.readFrom(bb);
               case 0x21:
                   // discriminator value 0x21L=0x21L for class OFBsnPduRxRequestVer13
                   return OFBsnPduRxRequestVer13.READER.readFrom(bb);
               case 0x23:
                   // discriminator value 0x23L=0x23L for class OFBsnPduRxTimeoutVer13
                   return OFBsnPduRxTimeoutVer13.READER.readFrom(bb);
               case 0x20:
                   // discriminator value 0x20L=0x20L for class OFBsnPduTxReplyVer13
                   return OFBsnPduTxReplyVer13.READER.readFrom(bb);
               case 0x1f:
                   // discriminator value 0x1fL=0x1fL for class OFBsnPduTxRequestVer13
                   return OFBsnPduTxRequestVer13.READER.readFrom(bb);
               case 0x3:
                   // discriminator value 0x3L=0x3L for class OFBsnSetMirroringVer13
                   return OFBsnSetMirroringVer13.READER.readFrom(bb);
               case 0x19:
                   // discriminator value 0x19L=0x19L for class OFBsnSetPktinSuppressionReplyVer13
                   return OFBsnSetPktinSuppressionReplyVer13.READER.readFrom(bb);
               case 0xb:
                   // discriminator value 0xbL=0xbL for class OFBsnSetPktinSuppressionRequestVer13
                   return OFBsnSetPktinSuppressionRequestVer13.READER.readFrom(bb);
               case 0x10:
                   // discriminator value 0x10L=0x10L for class OFBsnVirtualPortCreateReplyVer13
                   return OFBsnVirtualPortCreateReplyVer13.READER.readFrom(bb);
               case 0xf:
                   // discriminator value 0xfL=0xfL for class OFBsnVirtualPortCreateRequestVer13
                   return OFBsnVirtualPortCreateRequestVer13.READER.readFrom(bb);
               case 0x1a:
                   // discriminator value 0x1aL=0x1aL for class OFBsnVirtualPortRemoveReplyVer13
                   return OFBsnVirtualPortRemoveReplyVer13.READER.readFrom(bb);
               case 0x11:
                   // discriminator value 0x11L=0x11L for class OFBsnVirtualPortRemoveRequestVer13
                   return OFBsnVirtualPortRemoveRequestVer13.READER.readFrom(bb);
               case 0x3c:
                   // discriminator value 0x3cL=0x3cL for class OFBsnArpIdleVer13
                   return OFBsnArpIdleVer13.READER.readFrom(bb);
               case 0x39:
                   // discriminator value 0x39L=0x39L for class OFBsnControllerConnectionsReplyVer13
                   return OFBsnControllerConnectionsReplyVer13.READER.readFrom(bb);
               case 0x38:
                   // discriminator value 0x38L=0x38L for class OFBsnControllerConnectionsRequestVer13
                   return OFBsnControllerConnectionsRequestVer13.READER.readFrom(bb);
               case 0x28:
                   // discriminator value 0x28L=0x28L for class OFBsnFlowIdleVer13
                   return OFBsnFlowIdleVer13.READER.readFrom(bb);
               case 0x27:
                   // discriminator value 0x27L=0x27L for class OFBsnFlowIdleEnableGetReplyVer13
                   return OFBsnFlowIdleEnableGetReplyVer13.READER.readFrom(bb);
               case 0x26:
                   // discriminator value 0x26L=0x26L for class OFBsnFlowIdleEnableGetRequestVer13
                   return OFBsnFlowIdleEnableGetRequestVer13.READER.readFrom(bb);
               case 0x25:
                   // discriminator value 0x25L=0x25L for class OFBsnFlowIdleEnableSetReplyVer13
                   return OFBsnFlowIdleEnableSetReplyVer13.READER.readFrom(bb);
               case 0x24:
                   // discriminator value 0x24L=0x24L for class OFBsnFlowIdleEnableSetRequestVer13
                   return OFBsnFlowIdleEnableSetRequestVer13.READER.readFrom(bb);
               case 0x31:
                   // discriminator value 0x31L=0x31L for class OFBsnGentableClearReplyVer13
                   return OFBsnGentableClearReplyVer13.READER.readFrom(bb);
               case 0x30:
                   // discriminator value 0x30L=0x30L for class OFBsnGentableClearRequestVer13
                   return OFBsnGentableClearRequestVer13.READER.readFrom(bb);
               case 0x2e:
                   // discriminator value 0x2eL=0x2eL for class OFBsnGentableEntryAddVer13
                   return OFBsnGentableEntryAddVer13.READER.readFrom(bb);
               case 0x2f:
                   // discriminator value 0x2fL=0x2fL for class OFBsnGentableEntryDeleteVer13
                   return OFBsnGentableEntryDeleteVer13.READER.readFrom(bb);
               case 0x32:
                   // discriminator value 0x32L=0x32L for class OFBsnGentableSetBucketsSizeVer13
                   return OFBsnGentableSetBucketsSizeVer13.READER.readFrom(bb);
               case 0x34:
                   // discriminator value 0x34L=0x34L for class OFBsnGetSwitchPipelineReplyVer13
                   return OFBsnGetSwitchPipelineReplyVer13.READER.readFrom(bb);
               case 0x33:
                   // discriminator value 0x33L=0x33L for class OFBsnGetSwitchPipelineRequestVer13
                   return OFBsnGetSwitchPipelineRequestVer13.READER.readFrom(bb);
               case 0x2b:
                   // discriminator value 0x2bL=0x2bL for class OFBsnLacpConvergenceNotifVer13
                   return OFBsnLacpConvergenceNotifVer13.READER.readFrom(bb);
               case 0x3f:
                   // discriminator value 0x3fL=0x3fL for class OFBsnLogVer13
                   return OFBsnLogVer13.READER.readFrom(bb);
               case 0x40:
                   // discriminator value 0x40L=0x40L for class OFBsnLuaUploadVer13
                   return OFBsnLuaUploadVer13.READER.readFrom(bb);
               case 0x37:
                   // discriminator value 0x37L=0x37L for class OFBsnRoleStatusVer13
                   return OFBsnRoleStatusVer13.READER.readFrom(bb);
               case 0x3b:
                   // discriminator value 0x3bL=0x3bL for class OFBsnSetAuxCxnsReplyVer13
                   return OFBsnSetAuxCxnsReplyVer13.READER.readFrom(bb);
               case 0x3a:
                   // discriminator value 0x3aL=0x3aL for class OFBsnSetAuxCxnsRequestVer13
                   return OFBsnSetAuxCxnsRequestVer13.READER.readFrom(bb);
               case 0x2a:
                   // discriminator value 0x2aL=0x2aL for class OFBsnSetLacpReplyVer13
                   return OFBsnSetLacpReplyVer13.READER.readFrom(bb);
               case 0x29:
                   // discriminator value 0x29L=0x29L for class OFBsnSetLacpRequestVer13
                   return OFBsnSetLacpRequestVer13.READER.readFrom(bb);
               case 0x36:
                   // discriminator value 0x36L=0x36L for class OFBsnSetSwitchPipelineReplyVer13
                   return OFBsnSetSwitchPipelineReplyVer13.READER.readFrom(bb);
               case 0x35:
                   // discriminator value 0x35L=0x35L for class OFBsnSetSwitchPipelineRequestVer13
                   return OFBsnSetSwitchPipelineRequestVer13.READER.readFrom(bb);
               case 0x3d:
                   // discriminator value 0x3dL=0x3dL for class OFBsnTableSetBucketsSizeVer13
                   return OFBsnTableSetBucketsSizeVer13.READER.readFrom(bb);
               case 0x2d:
                   // discriminator value 0x2dL=0x2dL for class OFBsnTimeReplyVer13
                   return OFBsnTimeReplyVer13.READER.readFrom(bb);
               case 0x2c:
                   // discriminator value 0x2cL=0x2cL for class OFBsnTimeRequestVer13
                   return OFBsnTimeRequestVer13.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator subtype of class OFBsnHeaderVer13: " + subtype);
            }
        }
    }
}
