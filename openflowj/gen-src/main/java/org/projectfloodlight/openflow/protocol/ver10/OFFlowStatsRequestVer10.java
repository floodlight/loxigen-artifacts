// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver10;

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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import com.google.common.collect.ImmutableSet;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFFlowStatsRequestVer10 implements OFFlowStatsRequest {
    private static final Logger logger = LoggerFactory.getLogger(OFFlowStatsRequestVer10.class);
    // version: 1.0
    final static byte WIRE_VERSION = 1;
    final static int LENGTH = 56;

        private final static long DEFAULT_XID = 0x0L;
        private final static Set<OFStatsRequestFlags> DEFAULT_FLAGS = ImmutableSet.<OFStatsRequestFlags>of();
        private final static Match DEFAULT_MATCH = OFFactoryVer10.MATCH_WILDCARD_ALL;
        private final static TableId DEFAULT_TABLE_ID = TableId.ALL;
        private final static OFPort DEFAULT_OUT_PORT = OFPort.ANY;

    // OF message fields
    private final long xid;
    private final Set<OFStatsRequestFlags> flags;
    private final Match match;
    private final TableId tableId;
    private final OFPort outPort;
//
    // Immutable default instance
    final static OFFlowStatsRequestVer10 DEFAULT = new OFFlowStatsRequestVer10(
        DEFAULT_XID, DEFAULT_FLAGS, DEFAULT_MATCH, DEFAULT_TABLE_ID, DEFAULT_OUT_PORT
    );

    // package private constructor - used by readers, builders, and factory
    OFFlowStatsRequestVer10(long xid, Set<OFStatsRequestFlags> flags, Match match, TableId tableId, OFPort outPort) {
        if(flags == null) {
            throw new NullPointerException("OFFlowStatsRequestVer10: property flags cannot be null");
        }
        if(match == null) {
            throw new NullPointerException("OFFlowStatsRequestVer10: property match cannot be null");
        }
        if(tableId == null) {
            throw new NullPointerException("OFFlowStatsRequestVer10: property tableId cannot be null");
        }
        if(outPort == null) {
            throw new NullPointerException("OFFlowStatsRequestVer10: property outPort cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.flags = flags;
        this.match = match;
        this.tableId = tableId;
        this.outPort = outPort;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_10;
    }

    @Override
    public OFType getType() {
        return OFType.STATS_REQUEST;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFStatsType getStatsType() {
        return OFStatsType.FLOW;
    }

    @Override
    public Set<OFStatsRequestFlags> getFlags() {
        return flags;
    }

    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFPort getOutPort() {
        return outPort;
    }

    @Override
    public OFGroup getOutGroup()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property outGroup not supported in version 1.0");
    }

    @Override
    public U64 getCookie()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property cookie not supported in version 1.0");
    }

    @Override
    public U64 getCookieMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property cookieMask not supported in version 1.0");
    }



    public OFFlowStatsRequest.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFFlowStatsRequest.Builder {
        final OFFlowStatsRequestVer10 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean flagsSet;
        private Set<OFStatsRequestFlags> flags;
        private boolean matchSet;
        private Match match;
        private boolean tableIdSet;
        private TableId tableId;
        private boolean outPortSet;
        private OFPort outPort;

        BuilderWithParent(OFFlowStatsRequestVer10 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_10;
    }

    @Override
    public OFType getType() {
        return OFType.STATS_REQUEST;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFFlowStatsRequest.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public OFStatsType getStatsType() {
        return OFStatsType.FLOW;
    }

    @Override
    public Set<OFStatsRequestFlags> getFlags() {
        return flags;
    }

    @Override
    public OFFlowStatsRequest.Builder setFlags(Set<OFStatsRequestFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public OFFlowStatsRequest.Builder setMatch(Match match) {
        this.match = match;
        this.matchSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFFlowStatsRequest.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public OFPort getOutPort() {
        return outPort;
    }

    @Override
    public OFFlowStatsRequest.Builder setOutPort(OFPort outPort) {
        this.outPort = outPort;
        this.outPortSet = true;
        return this;
    }
    @Override
    public OFGroup getOutGroup()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property outGroup not supported in version 1.0");
    }

    @Override
    public OFFlowStatsRequest.Builder setOutGroup(OFGroup outGroup) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property outGroup not supported in version 1.0");
    }
    @Override
    public U64 getCookie()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property cookie not supported in version 1.0");
    }

    @Override
    public OFFlowStatsRequest.Builder setCookie(U64 cookie) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property cookie not supported in version 1.0");
    }
    @Override
    public U64 getCookieMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property cookieMask not supported in version 1.0");
    }

    @Override
    public OFFlowStatsRequest.Builder setCookieMask(U64 cookieMask) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property cookieMask not supported in version 1.0");
    }


        @Override
        public OFFlowStatsRequest build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                Set<OFStatsRequestFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                Match match = this.matchSet ? this.match : parentMessage.match;
                if(match == null)
                    throw new NullPointerException("Property match must not be null");
                TableId tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                if(tableId == null)
                    throw new NullPointerException("Property tableId must not be null");
                OFPort outPort = this.outPortSet ? this.outPort : parentMessage.outPort;
                if(outPort == null)
                    throw new NullPointerException("Property outPort must not be null");

                //
                return new OFFlowStatsRequestVer10(
                    xid,
                    flags,
                    match,
                    tableId,
                    outPort
                );
        }

    }

    static class Builder implements OFFlowStatsRequest.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean flagsSet;
        private Set<OFStatsRequestFlags> flags;
        private boolean matchSet;
        private Match match;
        private boolean tableIdSet;
        private TableId tableId;
        private boolean outPortSet;
        private OFPort outPort;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_10;
    }

    @Override
    public OFType getType() {
        return OFType.STATS_REQUEST;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFFlowStatsRequest.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public OFStatsType getStatsType() {
        return OFStatsType.FLOW;
    }

    @Override
    public Set<OFStatsRequestFlags> getFlags() {
        return flags;
    }

    @Override
    public OFFlowStatsRequest.Builder setFlags(Set<OFStatsRequestFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public OFFlowStatsRequest.Builder setMatch(Match match) {
        this.match = match;
        this.matchSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFFlowStatsRequest.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public OFPort getOutPort() {
        return outPort;
    }

    @Override
    public OFFlowStatsRequest.Builder setOutPort(OFPort outPort) {
        this.outPort = outPort;
        this.outPortSet = true;
        return this;
    }
    @Override
    public OFGroup getOutGroup()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property outGroup not supported in version 1.0");
    }

    @Override
    public OFFlowStatsRequest.Builder setOutGroup(OFGroup outGroup) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property outGroup not supported in version 1.0");
    }
    @Override
    public U64 getCookie()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property cookie not supported in version 1.0");
    }

    @Override
    public OFFlowStatsRequest.Builder setCookie(U64 cookie) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property cookie not supported in version 1.0");
    }
    @Override
    public U64 getCookieMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property cookieMask not supported in version 1.0");
    }

    @Override
    public OFFlowStatsRequest.Builder setCookieMask(U64 cookieMask) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property cookieMask not supported in version 1.0");
    }
//
        @Override
        public OFFlowStatsRequest build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            Set<OFStatsRequestFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            Match match = this.matchSet ? this.match : DEFAULT_MATCH;
            if(match == null)
                throw new NullPointerException("Property match must not be null");
            TableId tableId = this.tableIdSet ? this.tableId : DEFAULT_TABLE_ID;
            if(tableId == null)
                throw new NullPointerException("Property tableId must not be null");
            OFPort outPort = this.outPortSet ? this.outPort : DEFAULT_OUT_PORT;
            if(outPort == null)
                throw new NullPointerException("Property outPort must not be null");


            return new OFFlowStatsRequestVer10(
                    xid,
                    flags,
                    match,
                    tableId,
                    outPort
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFFlowStatsRequest> {
        @Override
        public OFFlowStatsRequest readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 1
            byte version = bb.readByte();
            if(version != (byte) 0x1)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_10(1), got="+version);
            // fixed value property type == 16
            byte type = bb.readByte();
            if(type != (byte) 0x10)
                throw new OFParseError("Wrong type: Expected=OFType.STATS_REQUEST(16), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 56)
                throw new OFParseError("Wrong length: Expected=56(56), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            // fixed value property statsType == 1
            short statsType = bb.readShort();
            if(statsType != (short) 0x1)
                throw new OFParseError("Wrong statsType: Expected=OFStatsType.FLOW(1), got="+statsType);
            Set<OFStatsRequestFlags> flags = OFStatsRequestFlagsSerializerVer10.readFrom(bb);
            Match match = ChannelUtilsVer10.readOFMatch(bb);
            TableId tableId = TableId.readByte(bb);
            // pad: 1 bytes
            bb.skipBytes(1);
            OFPort outPort = OFPort.read2Bytes(bb);

            OFFlowStatsRequestVer10 flowStatsRequestVer10 = new OFFlowStatsRequestVer10(
                    xid,
                      flags,
                      match,
                      tableId,
                      outPort
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", flowStatsRequestVer10);
            return flowStatsRequestVer10;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFFlowStatsRequestVer10Funnel FUNNEL = new OFFlowStatsRequestVer10Funnel();
    static class OFFlowStatsRequestVer10Funnel implements Funnel<OFFlowStatsRequestVer10> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFFlowStatsRequestVer10 message, PrimitiveSink sink) {
            // fixed value property version = 1
            sink.putByte((byte) 0x1);
            // fixed value property type = 16
            sink.putByte((byte) 0x10);
            // fixed value property length = 56
            sink.putShort((short) 0x38);
            sink.putLong(message.xid);
            // fixed value property statsType = 1
            sink.putShort((short) 0x1);
            OFStatsRequestFlagsSerializerVer10.putTo(message.flags, sink);
            message.match.putTo(sink);
            message.tableId.putTo(sink);
            // skip pad (1 bytes)
            message.outPort.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFFlowStatsRequestVer10> {
        @Override
        public void write(ByteBuf bb, OFFlowStatsRequestVer10 message) {
            // fixed value property version = 1
            bb.writeByte((byte) 0x1);
            // fixed value property type = 16
            bb.writeByte((byte) 0x10);
            // fixed value property length = 56
            bb.writeShort((short) 0x38);
            bb.writeInt(U32.t(message.xid));
            // fixed value property statsType = 1
            bb.writeShort((short) 0x1);
            OFStatsRequestFlagsSerializerVer10.writeTo(bb, message.flags);
            message.match.writeTo(bb);
            message.tableId.writeByte(bb);
            // pad: 1 bytes
            bb.writeZero(1);
            message.outPort.write2Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFFlowStatsRequestVer10(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("match=").append(match);
        b.append(", ");
        b.append("tableId=").append(tableId);
        b.append(", ");
        b.append("outPort=").append(outPort);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFFlowStatsRequestVer10 other = (OFFlowStatsRequestVer10) obj;

        if( xid != other.xid)
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (match == null) {
            if (other.match != null)
                return false;
        } else if (!match.equals(other.match))
            return false;
        if (tableId == null) {
            if (other.tableId != null)
                return false;
        } else if (!tableId.equals(other.tableId))
            return false;
        if (outPort == null) {
            if (other.outPort != null)
                return false;
        } else if (!outPort.equals(other.outPort))
            return false;
        return true;
    }

    @Override
    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFFlowStatsRequestVer10 other = (OFFlowStatsRequestVer10) obj;

        // ignore XID
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (match == null) {
            if (other.match != null)
                return false;
        } else if (!match.equals(other.match))
            return false;
        if (tableId == null) {
            if (other.tableId != null)
                return false;
        } else if (!tableId.equals(other.tableId))
            return false;
        if (outPort == null) {
            if (other.outPort != null)
                return false;
        } else if (!outPort.equals(other.outPort))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((match == null) ? 0 : match.hashCode());
        result = prime * result + ((tableId == null) ? 0 : tableId.hashCode());
        result = prime * result + ((outPort == null) ? 0 : outPort.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((match == null) ? 0 : match.hashCode());
        result = prime * result + ((tableId == null) ? 0 : tableId.hashCode());
        result = prime * result + ((outPort == null) ? 0 : outPort.hashCode());
        return result;
    }

}
