// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnGentableDescStatsEntryVer15 implements OFBsnGentableDescStatsEntry {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnGentableDescStatsEntryVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 48;

        private final static String DEFAULT_NAME = "";
        private final static long DEFAULT_BUCKETS_SIZE = 0x0L;
        private final static long DEFAULT_MAX_ENTRIES = 0x0L;

    // OF message fields
    private final GenTableId tableId;
    private final String name;
    private final long bucketsSize;
    private final long maxEntries;
//

    // package private constructor - used by readers, builders, and factory
    OFBsnGentableDescStatsEntryVer15(GenTableId tableId, String name, long bucketsSize, long maxEntries) {
        if(tableId == null) {
            throw new NullPointerException("OFBsnGentableDescStatsEntryVer15: property tableId cannot be null");
        }
        if(name == null) {
            throw new NullPointerException("OFBsnGentableDescStatsEntryVer15: property name cannot be null");
        }
        this.tableId = tableId;
        this.name = name;
        this.bucketsSize = U32.normalize(bucketsSize);
        this.maxEntries = U32.normalize(maxEntries);
    }

    // Accessors for OF message fields
    @Override
    public GenTableId getTableId() {
        return tableId;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public long getBucketsSize() {
        return bucketsSize;
    }

    @Override
    public long getMaxEntries() {
        return maxEntries;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFBsnGentableDescStatsEntry.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnGentableDescStatsEntry.Builder {
        final OFBsnGentableDescStatsEntryVer15 parentMessage;

        // OF message fields
        private boolean tableIdSet;
        private GenTableId tableId;
        private boolean nameSet;
        private String name;
        private boolean bucketsSizeSet;
        private long bucketsSize;
        private boolean maxEntriesSet;
        private long maxEntries;

        BuilderWithParent(OFBsnGentableDescStatsEntryVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public GenTableId getTableId() {
        return tableId;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setTableId(GenTableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setName(String name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public long getBucketsSize() {
        return bucketsSize;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setBucketsSize(long bucketsSize) {
        this.bucketsSize = bucketsSize;
        this.bucketsSizeSet = true;
        return this;
    }
    @Override
    public long getMaxEntries() {
        return maxEntries;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setMaxEntries(long maxEntries) {
        this.maxEntries = maxEntries;
        this.maxEntriesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFBsnGentableDescStatsEntry build() {
                GenTableId tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                if(tableId == null)
                    throw new NullPointerException("Property tableId must not be null");
                String name = this.nameSet ? this.name : parentMessage.name;
                if(name == null)
                    throw new NullPointerException("Property name must not be null");
                long bucketsSize = this.bucketsSizeSet ? this.bucketsSize : parentMessage.bucketsSize;
                long maxEntries = this.maxEntriesSet ? this.maxEntries : parentMessage.maxEntries;

                //
                return new OFBsnGentableDescStatsEntryVer15(
                    tableId,
                    name,
                    bucketsSize,
                    maxEntries
                );
        }

    }

    static class Builder implements OFBsnGentableDescStatsEntry.Builder {
        // OF message fields
        private boolean tableIdSet;
        private GenTableId tableId;
        private boolean nameSet;
        private String name;
        private boolean bucketsSizeSet;
        private long bucketsSize;
        private boolean maxEntriesSet;
        private long maxEntries;

    @Override
    public GenTableId getTableId() {
        return tableId;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setTableId(GenTableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setName(String name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public long getBucketsSize() {
        return bucketsSize;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setBucketsSize(long bucketsSize) {
        this.bucketsSize = bucketsSize;
        this.bucketsSizeSet = true;
        return this;
    }
    @Override
    public long getMaxEntries() {
        return maxEntries;
    }

    @Override
    public OFBsnGentableDescStatsEntry.Builder setMaxEntries(long maxEntries) {
        this.maxEntries = maxEntries;
        this.maxEntriesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFBsnGentableDescStatsEntry build() {
            if(!this.tableIdSet)
                throw new IllegalStateException("Property tableId doesn't have default value -- must be set");
            if(tableId == null)
                throw new NullPointerException("Property tableId must not be null");
            String name = this.nameSet ? this.name : DEFAULT_NAME;
            if(name == null)
                throw new NullPointerException("Property name must not be null");
            long bucketsSize = this.bucketsSizeSet ? this.bucketsSize : DEFAULT_BUCKETS_SIZE;
            long maxEntries = this.maxEntriesSet ? this.maxEntries : DEFAULT_MAX_ENTRIES;


            return new OFBsnGentableDescStatsEntryVer15(
                    tableId,
                    name,
                    bucketsSize,
                    maxEntries
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnGentableDescStatsEntry> {
        @Override
        public OFBsnGentableDescStatsEntry readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            int length = U16.f(bb.readShort());
            if(length != 48)
                throw new OFParseError("Wrong length: Expected=48(48), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            GenTableId tableId = GenTableId.read2Bytes(bb);
            String name = ChannelUtils.readFixedLengthString(bb, 32);
            long bucketsSize = U32.f(bb.readInt());
            long maxEntries = U32.f(bb.readInt());
            // pad: 4 bytes
            bb.skipBytes(4);

            OFBsnGentableDescStatsEntryVer15 bsnGentableDescStatsEntryVer15 = new OFBsnGentableDescStatsEntryVer15(
                    tableId,
                      name,
                      bucketsSize,
                      maxEntries
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnGentableDescStatsEntryVer15);
            return bsnGentableDescStatsEntryVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnGentableDescStatsEntryVer15Funnel FUNNEL = new OFBsnGentableDescStatsEntryVer15Funnel();
    static class OFBsnGentableDescStatsEntryVer15Funnel implements Funnel<OFBsnGentableDescStatsEntryVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnGentableDescStatsEntryVer15 message, PrimitiveSink sink) {
            // fixed value property length = 48
            sink.putShort((short) 0x30);
            message.tableId.putTo(sink);
            sink.putUnencodedChars(message.name);
            sink.putLong(message.bucketsSize);
            sink.putLong(message.maxEntries);
            // skip pad (4 bytes)
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnGentableDescStatsEntryVer15> {
        @Override
        public void write(ByteBuf bb, OFBsnGentableDescStatsEntryVer15 message) {
            // fixed value property length = 48
            bb.writeShort((short) 0x30);
            message.tableId.write2Bytes(bb);
            ChannelUtils.writeFixedLengthString(bb, message.name, 32);
            bb.writeInt(U32.t(message.bucketsSize));
            bb.writeInt(U32.t(message.maxEntries));
            // pad: 4 bytes
            bb.writeZero(4);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnGentableDescStatsEntryVer15(");
        b.append("tableId=").append(tableId);
        b.append(", ");
        b.append("name=").append(name);
        b.append(", ");
        b.append("bucketsSize=").append(bucketsSize);
        b.append(", ");
        b.append("maxEntries=").append(maxEntries);
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
        OFBsnGentableDescStatsEntryVer15 other = (OFBsnGentableDescStatsEntryVer15) obj;

        if (tableId == null) {
            if (other.tableId != null)
                return false;
        } else if (!tableId.equals(other.tableId))
            return false;
        if (name == null) {
            if (other.name != null)
                return false;
        } else if (!name.equals(other.name))
            return false;
        if( bucketsSize != other.bucketsSize)
            return false;
        if( maxEntries != other.maxEntries)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((tableId == null) ? 0 : tableId.hashCode());
        result = prime * result + ((name == null) ? 0 : name.hashCode());
        result = prime *  (int) (bucketsSize ^ (bucketsSize >>> 32));
        result = prime *  (int) (maxEntries ^ (maxEntries >>> 32));
        return result;
    }

}
