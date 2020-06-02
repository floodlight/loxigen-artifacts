// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_factory_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver14;

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


public class OFInstructionIdsVer14 implements OFInstructionIds {
    public final static OFInstructionIdsVer14 INSTANCE = new OFInstructionIdsVer14();




    public OFInstructionIdApplyActions applyActions() {
        return OFInstructionIdApplyActionsVer14.INSTANCE;
    }

    public OFInstructionIdBsnArpOffload bsnArpOffload() {
        return OFInstructionIdBsnArpOffloadVer14.INSTANCE;
    }

    public OFInstructionIdBsnAutoNegotiation bsnAutoNegotiation() {
        return OFInstructionIdBsnAutoNegotiationVer14.INSTANCE;
    }

    public OFInstructionIdBsnDeny bsnDeny() {
        return OFInstructionIdBsnDenyVer14.INSTANCE;
    }

    public OFInstructionIdBsnDhcpOffload bsnDhcpOffload() {
        return OFInstructionIdBsnDhcpOffloadVer14.INSTANCE;
    }

    public OFInstructionIdBsnDirectedBroadcast bsnDirectedBroadcast() {
        return OFInstructionIdBsnDirectedBroadcastVer14.INSTANCE;
    }

    public OFInstructionIdBsnDisableL3 bsnDisableL3() {
        return OFInstructionIdBsnDisableL3Ver14.INSTANCE;
    }

    public OFInstructionIdBsnDisableSplitHorizonCheck bsnDisableSplitHorizonCheck() {
        throw new UnsupportedOperationException("OFInstructionIdBsnDisableSplitHorizonCheck not supported in version 1.4");
    }

    public OFInstructionIdBsnDisableSrcMacCheck bsnDisableSrcMacCheck() {
        return OFInstructionIdBsnDisableSrcMacCheckVer14.INSTANCE;
    }

    public OFInstructionIdBsnDisableVlanCounters bsnDisableVlanCounters() {
        return OFInstructionIdBsnDisableVlanCountersVer14.INSTANCE;
    }

    public OFInstructionIdBsnHashSelect bsnHashSelect() {
        return OFInstructionIdBsnHashSelectVer14.INSTANCE;
    }

    public OFInstructionIdBsnInternalPriority bsnInternalPriority() {
        return OFInstructionIdBsnInternalPriorityVer14.INSTANCE;
    }

    public OFInstructionIdBsnNdpOffload bsnNdpOffload() {
        return OFInstructionIdBsnNdpOffloadVer14.INSTANCE;
    }

    public OFInstructionIdBsnPacketOfDeath bsnPacketOfDeath() {
        return OFInstructionIdBsnPacketOfDeathVer14.INSTANCE;
    }

    public OFInstructionIdBsnPermit bsnPermit() {
        return OFInstructionIdBsnPermitVer14.INSTANCE;
    }

    public OFInstructionIdBsnPrioritizePdus bsnPrioritizePdus() {
        return OFInstructionIdBsnPrioritizePdusVer14.INSTANCE;
    }

    public OFInstructionIdBsnRequireVlanXlate bsnRequireVlanXlate() {
        return OFInstructionIdBsnRequireVlanXlateVer14.INSTANCE;
    }

    public OFInstructionIdBsnSpanDestination bsnSpanDestination() {
        return OFInstructionIdBsnSpanDestinationVer14.INSTANCE;
    }

    public OFInstructionIdClearActions clearActions() {
        return OFInstructionIdClearActionsVer14.INSTANCE;
    }

    public OFInstructionIdGotoTable gotoTable() {
        return OFInstructionIdGotoTableVer14.INSTANCE;
    }

    public OFInstructionIdMeter meter() {
        return OFInstructionIdMeterVer14.INSTANCE;
    }

    public OFInstructionIdStatTrigger statTrigger() {
        throw new UnsupportedOperationException("OFInstructionIdStatTrigger not supported in version 1.4");
    }

    public OFInstructionIdWriteActions writeActions() {
        return OFInstructionIdWriteActionsVer14.INSTANCE;
    }

    public OFInstructionIdWriteMetadata writeMetadata() {
        return OFInstructionIdWriteMetadataVer14.INSTANCE;
    }

    public OFMessageReader<OFInstructionId> getReader() {
        return OFInstructionIdVer14.READER;
    }


    public OFVersion getVersion() {
            return OFVersion.OF_14;
    }
}
