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
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import java.util.List;
import java.util.Set;


public class OFInstructionsVer13 implements OFInstructions {
    public final static OFInstructionsVer13 INSTANCE = new OFInstructionsVer13();




    public OFInstructionApplyActions.Builder buildApplyActions() {
        return new OFInstructionApplyActionsVer13.Builder();
    }
    public OFInstructionApplyActions applyActions(List<OFAction> actions) {
        return new OFInstructionApplyActionsVer13(
                actions
                    );
    }

    public OFInstructionBsnArpOffload bsnArpOffload() {
        return OFInstructionBsnArpOffloadVer13.INSTANCE;
    }

    public OFInstructionBsnAutoNegotiation bsnAutoNegotiation() {
        return OFInstructionBsnAutoNegotiationVer13.INSTANCE;
    }

    public OFInstructionBsnDeny bsnDeny() {
        return OFInstructionBsnDenyVer13.INSTANCE;
    }

    public OFInstructionBsnDhcpOffload bsnDhcpOffload() {
        return OFInstructionBsnDhcpOffloadVer13.INSTANCE;
    }

    public OFInstructionBsnDirectedBroadcast bsnDirectedBroadcast() {
        return OFInstructionBsnDirectedBroadcastVer13.INSTANCE;
    }

    public OFInstructionBsnDisableL3 bsnDisableL3() {
        return OFInstructionBsnDisableL3Ver13.INSTANCE;
    }

    public OFInstructionBsnDisableSplitHorizonCheck bsnDisableSplitHorizonCheck() {
        return OFInstructionBsnDisableSplitHorizonCheckVer13.INSTANCE;
    }

    public OFInstructionBsnDisableSrcMacCheck bsnDisableSrcMacCheck() {
        return OFInstructionBsnDisableSrcMacCheckVer13.INSTANCE;
    }

    public OFInstructionBsnDisableVlanCounters bsnDisableVlanCounters() {
        return OFInstructionBsnDisableVlanCountersVer13.INSTANCE;
    }

    public OFInstructionBsnHashSelect.Builder buildBsnHashSelect() {
        return new OFInstructionBsnHashSelectVer13.Builder();
    }
    public OFInstructionBsnHashSelect bsnHashSelect(Set<OFBsnHashSelectFlags> flags) {
        return new OFInstructionBsnHashSelectVer13(
                flags
                    );
    }

    public OFInstructionBsnInternalPriority.Builder buildBsnInternalPriority() {
        return new OFInstructionBsnInternalPriorityVer13.Builder();
    }
    public OFInstructionBsnInternalPriority bsnInternalPriority(long value) {
        return new OFInstructionBsnInternalPriorityVer13(
                value
                    );
    }

    public OFInstructionBsnNdpOffload bsnNdpOffload() {
        return OFInstructionBsnNdpOffloadVer13.INSTANCE;
    }

    public OFInstructionBsnPacketOfDeath bsnPacketOfDeath() {
        return OFInstructionBsnPacketOfDeathVer13.INSTANCE;
    }

    public OFInstructionBsnPermit bsnPermit() {
        return OFInstructionBsnPermitVer13.INSTANCE;
    }

    public OFInstructionBsnPrioritizePdus bsnPrioritizePdus() {
        return OFInstructionBsnPrioritizePdusVer13.INSTANCE;
    }

    public OFInstructionBsnRequireVlanXlate bsnRequireVlanXlate() {
        return OFInstructionBsnRequireVlanXlateVer13.INSTANCE;
    }

    public OFInstructionBsnSpanDestination bsnSpanDestination() {
        return OFInstructionBsnSpanDestinationVer13.INSTANCE;
    }

    public OFInstructionClearActions clearActions() {
        return OFInstructionClearActionsVer13.INSTANCE;
    }

    public OFInstructionGotoTable.Builder buildGotoTable() {
        return new OFInstructionGotoTableVer13.Builder();
    }
    public OFInstructionGotoTable gotoTable(TableId tableId) {
        return new OFInstructionGotoTableVer13(
                tableId
                    );
    }

    public OFInstructionMeter.Builder buildMeter() {
        return new OFInstructionMeterVer13.Builder();
    }
    public OFInstructionMeter meter(long meterId) {
        return new OFInstructionMeterVer13(
                meterId
                    );
    }

    public OFInstructionStatTrigger.Builder buildStatTrigger() {
        throw new UnsupportedOperationException("OFInstructionStatTrigger not supported in version 1.3");
    }
    public OFInstructionStatTrigger statTrigger(Set<OFStatTriggerFlags> flags, OFOxsList thresholds) {
        throw new UnsupportedOperationException("OFInstructionStatTrigger not supported in version 1.3");
    }

    public OFInstructionWriteActions.Builder buildWriteActions() {
        return new OFInstructionWriteActionsVer13.Builder();
    }
    public OFInstructionWriteActions writeActions(List<OFAction> actions) {
        return new OFInstructionWriteActionsVer13(
                actions
                    );
    }

    public OFInstructionWriteMetadata.Builder buildWriteMetadata() {
        return new OFInstructionWriteMetadataVer13.Builder();
    }
    public OFInstructionWriteMetadata writeMetadata(U64 metadata, U64 metadataMask) {
        return new OFInstructionWriteMetadataVer13(
                metadata,
                      metadataMask
                    );
    }

    public OFMessageReader<OFInstruction> getReader() {
        return OFInstructionVer13.READER;
    }


    public OFVersion getVersion() {
            return OFVersion.OF_13;
    }
}
