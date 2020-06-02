// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_interface.java
// Do not modify

package org.projectfloodlight.openflow.protocol;

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
import io.netty.buffer.ByteBuf;

public interface OFFlowStatsEntry extends OFObject {
    List<OFAction> getActions() throws UnsupportedOperationException;
    U64 getByteCount() throws UnsupportedOperationException;
    U64 getCookie();
    long getDurationNsec() throws UnsupportedOperationException;
    long getDurationSec() throws UnsupportedOperationException;
    Set<OFFlowModFlags> getFlags() throws UnsupportedOperationException;
    int getHardTimeout();
    int getIdleTimeout();
    int getImportance() throws UnsupportedOperationException;
    List<OFInstruction> getInstructions() throws UnsupportedOperationException;
    Match getMatch();
    U64 getPacketCount() throws UnsupportedOperationException;
    int getPriority();
    Stat getStats() throws UnsupportedOperationException;
    TableId getTableId();
    OFVersion getVersion();

    void writeTo(ByteBuf channelBuffer);

    Builder createBuilder();
    public interface Builder  {
        OFFlowStatsEntry build();
        List<OFAction> getActions() throws UnsupportedOperationException;
        Builder setActions(List<OFAction> actions) throws UnsupportedOperationException;
        U64 getByteCount() throws UnsupportedOperationException;
        Builder setByteCount(U64 byteCount) throws UnsupportedOperationException;
        U64 getCookie();
        Builder setCookie(U64 cookie);
        long getDurationNsec() throws UnsupportedOperationException;
        Builder setDurationNsec(long durationNsec) throws UnsupportedOperationException;
        long getDurationSec() throws UnsupportedOperationException;
        Builder setDurationSec(long durationSec) throws UnsupportedOperationException;
        Set<OFFlowModFlags> getFlags() throws UnsupportedOperationException;
        Builder setFlags(Set<OFFlowModFlags> flags) throws UnsupportedOperationException;
        int getHardTimeout();
        Builder setHardTimeout(int hardTimeout);
        int getIdleTimeout();
        Builder setIdleTimeout(int idleTimeout);
        int getImportance() throws UnsupportedOperationException;
        Builder setImportance(int importance) throws UnsupportedOperationException;
        List<OFInstruction> getInstructions() throws UnsupportedOperationException;
        Builder setInstructions(List<OFInstruction> instructions) throws UnsupportedOperationException;
        Match getMatch();
        Builder setMatch(Match match);
        U64 getPacketCount() throws UnsupportedOperationException;
        Builder setPacketCount(U64 packetCount) throws UnsupportedOperationException;
        int getPriority();
        Builder setPriority(int priority);
        Stat getStats() throws UnsupportedOperationException;
        Builder setStats(Stat stats) throws UnsupportedOperationException;
        TableId getTableId();
        Builder setTableId(TableId tableId);
        OFVersion getVersion();
    }
}
