// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.List;
import com.google.common.collect.ImmutableList;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnTlvReferenceVer14 implements OFBsnTlvReference {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvReferenceVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 6;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static int DEFAULT_TABLE_ID = 0x0;
        private final static List<OFBsnTlv> DEFAULT_KEY = ImmutableList.<OFBsnTlv>of();

    // OF message fields
    private final int tableId;
    private final List<OFBsnTlv> key;
//
    // Immutable default instance
    final static OFBsnTlvReferenceVer14 DEFAULT = new OFBsnTlvReferenceVer14(
        DEFAULT_TABLE_ID, DEFAULT_KEY
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvReferenceVer14(int tableId, List<OFBsnTlv> key) {
        if(key == null) {
            throw new NullPointerException("OFBsnTlvReferenceVer14: property key cannot be null");
        }
        this.tableId = U16.normalize(tableId);
        this.key = key;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x3b;
    }

    @Override
    public int getTableId() {
        return tableId;
    }

    @Override
    public List<OFBsnTlv> getKey() {
        return key;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFBsnTlvReference.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvReference.Builder {
        final OFBsnTlvReferenceVer14 parentMessage;

        // OF message fields
        private boolean tableIdSet;
        private int tableId;
        private boolean keySet;
        private List<OFBsnTlv> key;

        BuilderWithParent(OFBsnTlvReferenceVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x3b;
    }

    @Override
    public int getTableId() {
        return tableId;
    }

    @Override
    public OFBsnTlvReference.Builder setTableId(int tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public List<OFBsnTlv> getKey() {
        return key;
    }

    @Override
    public OFBsnTlvReference.Builder setKey(List<OFBsnTlv> key) {
        this.key = key;
        this.keySet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFBsnTlvReference build() {
                int tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                List<OFBsnTlv> key = this.keySet ? this.key : parentMessage.key;
                if(key == null)
                    throw new NullPointerException("Property key must not be null");

                //
                return new OFBsnTlvReferenceVer14(
                    tableId,
                    key
                );
        }

    }

    static class Builder implements OFBsnTlvReference.Builder {
        // OF message fields
        private boolean tableIdSet;
        private int tableId;
        private boolean keySet;
        private List<OFBsnTlv> key;

    @Override
    public int getType() {
        return 0x3b;
    }

    @Override
    public int getTableId() {
        return tableId;
    }

    @Override
    public OFBsnTlvReference.Builder setTableId(int tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public List<OFBsnTlv> getKey() {
        return key;
    }

    @Override
    public OFBsnTlvReference.Builder setKey(List<OFBsnTlv> key) {
        this.key = key;
        this.keySet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFBsnTlvReference build() {
            int tableId = this.tableIdSet ? this.tableId : DEFAULT_TABLE_ID;
            List<OFBsnTlv> key = this.keySet ? this.key : DEFAULT_KEY;
            if(key == null)
                throw new NullPointerException("Property key must not be null");


            return new OFBsnTlvReferenceVer14(
                    tableId,
                    key
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnTlvReference> {
        @Override
        public OFBsnTlvReference readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x3b
            short type = bb.readShort();
            if(type != (short) 0x3b)
                throw new OFParseError("Wrong type: Expected=0x3b(0x3b), got="+type);
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
            int tableId = U16.f(bb.readShort());
            List<OFBsnTlv> key = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFBsnTlvVer14.READER);

            OFBsnTlvReferenceVer14 bsnTlvReferenceVer14 = new OFBsnTlvReferenceVer14(
                    tableId,
                      key
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvReferenceVer14);
            return bsnTlvReferenceVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvReferenceVer14Funnel FUNNEL = new OFBsnTlvReferenceVer14Funnel();
    static class OFBsnTlvReferenceVer14Funnel implements Funnel<OFBsnTlvReferenceVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvReferenceVer14 message, PrimitiveSink sink) {
            // fixed value property type = 0x3b
            sink.putShort((short) 0x3b);
            // FIXME: skip funnel of length
            sink.putInt(message.tableId);
            FunnelUtils.putList(message.key, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvReferenceVer14> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvReferenceVer14 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 0x3b
            bb.writeShort((short) 0x3b);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeShort(U16.t(message.tableId));
            ChannelUtils.writeList(bb, message.key);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBsnTlvReferenceVer14: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvReferenceVer14(");
        b.append("tableId=").append(tableId);
        b.append(", ");
        b.append("key=").append(key);
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
        OFBsnTlvReferenceVer14 other = (OFBsnTlvReferenceVer14) obj;

        if( tableId != other.tableId)
            return false;
        if (key == null) {
            if (other.key != null)
                return false;
        } else if (!key.equals(other.key))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + tableId;
        result = prime * result + ((key == null) ? 0 : key.hashCode());
        return result;
    }

}
