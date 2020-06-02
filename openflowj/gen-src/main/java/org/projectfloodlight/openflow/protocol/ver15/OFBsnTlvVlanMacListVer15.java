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
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import com.google.common.collect.ImmutableList;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnTlvVlanMacListVer15 implements OFBsnTlvVlanMacList {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvVlanMacListVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 4;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static List<OFBsnVlanMac> DEFAULT_KEY = ImmutableList.<OFBsnVlanMac>of();

    // OF message fields
    private final List<OFBsnVlanMac> key;
//
    // Immutable default instance
    final static OFBsnTlvVlanMacListVer15 DEFAULT = new OFBsnTlvVlanMacListVer15(
        DEFAULT_KEY
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvVlanMacListVer15(List<OFBsnVlanMac> key) {
        if(key == null) {
            throw new NullPointerException("OFBsnTlvVlanMacListVer15: property key cannot be null");
        }
        this.key = key;
    }

    // Accessors for OF message fields
    @Override
    public List<OFBsnVlanMac> getKey() {
        return key;
    }

    @Override
    public int getType() {
        return 0x62;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFBsnTlvVlanMacList.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvVlanMacList.Builder {
        final OFBsnTlvVlanMacListVer15 parentMessage;

        // OF message fields
        private boolean keySet;
        private List<OFBsnVlanMac> key;

        BuilderWithParent(OFBsnTlvVlanMacListVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public List<OFBsnVlanMac> getKey() {
        return key;
    }

    @Override
    public OFBsnTlvVlanMacList.Builder setKey(List<OFBsnVlanMac> key) {
        this.key = key;
        this.keySet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0x62;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFBsnTlvVlanMacList build() {
                List<OFBsnVlanMac> key = this.keySet ? this.key : parentMessage.key;
                if(key == null)
                    throw new NullPointerException("Property key must not be null");

                //
                return new OFBsnTlvVlanMacListVer15(
                    key
                );
        }

    }

    static class Builder implements OFBsnTlvVlanMacList.Builder {
        // OF message fields
        private boolean keySet;
        private List<OFBsnVlanMac> key;

    @Override
    public List<OFBsnVlanMac> getKey() {
        return key;
    }

    @Override
    public OFBsnTlvVlanMacList.Builder setKey(List<OFBsnVlanMac> key) {
        this.key = key;
        this.keySet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0x62;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFBsnTlvVlanMacList build() {
            List<OFBsnVlanMac> key = this.keySet ? this.key : DEFAULT_KEY;
            if(key == null)
                throw new NullPointerException("Property key must not be null");


            return new OFBsnTlvVlanMacListVer15(
                    key
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnTlvVlanMacList> {
        @Override
        public OFBsnTlvVlanMacList readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x62
            short type = bb.readShort();
            if(type != (short) 0x62)
                throw new OFParseError("Wrong type: Expected=0x62(0x62), got="+type);
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
            List<OFBsnVlanMac> key = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFBsnVlanMacVer15.READER);

            OFBsnTlvVlanMacListVer15 bsnTlvVlanMacListVer15 = new OFBsnTlvVlanMacListVer15(
                    key
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvVlanMacListVer15);
            return bsnTlvVlanMacListVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvVlanMacListVer15Funnel FUNNEL = new OFBsnTlvVlanMacListVer15Funnel();
    static class OFBsnTlvVlanMacListVer15Funnel implements Funnel<OFBsnTlvVlanMacListVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvVlanMacListVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0x62
            sink.putShort((short) 0x62);
            // FIXME: skip funnel of length
            FunnelUtils.putList(message.key, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvVlanMacListVer15> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvVlanMacListVer15 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 0x62
            bb.writeShort((short) 0x62);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            ChannelUtils.writeList(bb, message.key);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBsnTlvVlanMacListVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvVlanMacListVer15(");
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
        OFBsnTlvVlanMacListVer15 other = (OFBsnTlvVlanMacListVer15) obj;

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

        result = prime * result + ((key == null) ? 0 : key.hashCode());
        return result;
    }

}
