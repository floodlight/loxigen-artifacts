// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver11;

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
import java.util.List;
import com.google.common.collect.ImmutableList;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFFlowStatsReplyVer11 implements OFFlowStatsReply {
    private static final Logger logger = LoggerFactory.getLogger(OFFlowStatsReplyVer11.class);
    // version: 1.1
    final static byte WIRE_VERSION = 2;
    final static int MINIMUM_LENGTH = 16;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static long DEFAULT_XID = 0x0L;
        private final static Set<OFStatsReplyFlags> DEFAULT_FLAGS = ImmutableSet.<OFStatsReplyFlags>of();
        private final static List<OFFlowStatsEntry> DEFAULT_ENTRIES = ImmutableList.<OFFlowStatsEntry>of();

    // OF message fields
    private final long xid;
    private final Set<OFStatsReplyFlags> flags;
    private final List<OFFlowStatsEntry> entries;
//
    // Immutable default instance
    final static OFFlowStatsReplyVer11 DEFAULT = new OFFlowStatsReplyVer11(
        DEFAULT_XID, DEFAULT_FLAGS, DEFAULT_ENTRIES
    );

    // package private constructor - used by readers, builders, and factory
    OFFlowStatsReplyVer11(long xid, Set<OFStatsReplyFlags> flags, List<OFFlowStatsEntry> entries) {
        if(flags == null) {
            throw new NullPointerException("OFFlowStatsReplyVer11: property flags cannot be null");
        }
        if(entries == null) {
            throw new NullPointerException("OFFlowStatsReplyVer11: property entries cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.flags = flags;
        this.entries = entries;
    }

    // Accessors for OF message fields
    @Override
    public List<OFFlowStatsEntry> getEntries() {
        return entries;
    }

    @Override
    public Set<OFStatsReplyFlags> getFlags() {
        return flags;
    }

    @Override
    public OFStatsType getStatsType() {
        return OFStatsType.FLOW;
    }

    @Override
    public OFType getType() {
        return OFType.STATS_REPLY;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public long getXid() {
        return xid;
    }



    public OFFlowStatsReply.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFFlowStatsReply.Builder {
        final OFFlowStatsReplyVer11 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean flagsSet;
        private Set<OFStatsReplyFlags> flags;
        private boolean entriesSet;
        private List<OFFlowStatsEntry> entries;

        BuilderWithParent(OFFlowStatsReplyVer11 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public List<OFFlowStatsEntry> getEntries() {
        return entries;
    }

    @Override
    public OFFlowStatsReply.Builder setEntries(List<OFFlowStatsEntry> entries) {
        this.entries = entries;
        this.entriesSet = true;
        return this;
    }
    @Override
    public Set<OFStatsReplyFlags> getFlags() {
        return flags;
    }

    @Override
    public OFFlowStatsReply.Builder setFlags(Set<OFStatsReplyFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public OFStatsType getStatsType() {
        return OFStatsType.FLOW;
    }

    @Override
    public OFType getType() {
        return OFType.STATS_REPLY;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFFlowStatsReply.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }


        @Override
        public OFFlowStatsReply build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                Set<OFStatsReplyFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                List<OFFlowStatsEntry> entries = this.entriesSet ? this.entries : parentMessage.entries;
                if(entries == null)
                    throw new NullPointerException("Property entries must not be null");

                //
                return new OFFlowStatsReplyVer11(
                    xid,
                    flags,
                    entries
                );
        }

    }

    static class Builder implements OFFlowStatsReply.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean flagsSet;
        private Set<OFStatsReplyFlags> flags;
        private boolean entriesSet;
        private List<OFFlowStatsEntry> entries;

    @Override
    public List<OFFlowStatsEntry> getEntries() {
        return entries;
    }

    @Override
    public OFFlowStatsReply.Builder setEntries(List<OFFlowStatsEntry> entries) {
        this.entries = entries;
        this.entriesSet = true;
        return this;
    }
    @Override
    public Set<OFStatsReplyFlags> getFlags() {
        return flags;
    }

    @Override
    public OFFlowStatsReply.Builder setFlags(Set<OFStatsReplyFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public OFStatsType getStatsType() {
        return OFStatsType.FLOW;
    }

    @Override
    public OFType getType() {
        return OFType.STATS_REPLY;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFFlowStatsReply.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
//
        @Override
        public OFFlowStatsReply build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            Set<OFStatsReplyFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            List<OFFlowStatsEntry> entries = this.entriesSet ? this.entries : DEFAULT_ENTRIES;
            if(entries == null)
                throw new NullPointerException("Property entries must not be null");


            return new OFFlowStatsReplyVer11(
                    xid,
                    flags,
                    entries
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFFlowStatsReply> {
        @Override
        public OFFlowStatsReply readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 2
            byte version = bb.readByte();
            if(version != (byte) 0x2)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_11(2), got="+version);
            // fixed value property type == 19
            byte type = bb.readByte();
            if(type != (byte) 0x13)
                throw new OFParseError("Wrong type: Expected=OFType.STATS_REPLY(19), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
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
            Set<OFStatsReplyFlags> flags = OFStatsReplyFlagsSerializerVer11.readFrom(bb);
            // pad: 4 bytes
            bb.skipBytes(4);
            List<OFFlowStatsEntry> entries = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFFlowStatsEntryVer11.READER);

            OFFlowStatsReplyVer11 flowStatsReplyVer11 = new OFFlowStatsReplyVer11(
                    xid,
                      flags,
                      entries
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", flowStatsReplyVer11);
            return flowStatsReplyVer11;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFFlowStatsReplyVer11Funnel FUNNEL = new OFFlowStatsReplyVer11Funnel();
    static class OFFlowStatsReplyVer11Funnel implements Funnel<OFFlowStatsReplyVer11> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFFlowStatsReplyVer11 message, PrimitiveSink sink) {
            // fixed value property version = 2
            sink.putByte((byte) 0x2);
            // fixed value property type = 19
            sink.putByte((byte) 0x13);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            // fixed value property statsType = 1
            sink.putShort((short) 0x1);
            OFStatsReplyFlagsSerializerVer11.putTo(message.flags, sink);
            // skip pad (4 bytes)
            FunnelUtils.putList(message.entries, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFFlowStatsReplyVer11> {
        @Override
        public void write(ByteBuf bb, OFFlowStatsReplyVer11 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 2
            bb.writeByte((byte) 0x2);
            // fixed value property type = 19
            bb.writeByte((byte) 0x13);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            // fixed value property statsType = 1
            bb.writeShort((short) 0x1);
            OFStatsReplyFlagsSerializerVer11.writeTo(bb, message.flags);
            // pad: 4 bytes
            bb.writeZero(4);
            ChannelUtils.writeList(bb, message.entries);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFFlowStatsReplyVer11: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFFlowStatsReplyVer11(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("entries=").append(entries);
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
        OFFlowStatsReplyVer11 other = (OFFlowStatsReplyVer11) obj;

        if( xid != other.xid)
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (entries == null) {
            if (other.entries != null)
                return false;
        } else if (!entries.equals(other.entries))
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
        OFFlowStatsReplyVer11 other = (OFFlowStatsReplyVer11) obj;

        // ignore XID
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (entries == null) {
            if (other.entries != null)
                return false;
        } else if (!entries.equals(other.entries))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((entries == null) ? 0 : entries.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((entries == null) ? 0 : entries.hashCode());
        return result;
    }

}
