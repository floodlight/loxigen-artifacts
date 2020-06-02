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

class OFPortDescPropBsnGenerationIdVer15 implements OFPortDescPropBsnGenerationId {
    private static final Logger logger = LoggerFactory.getLogger(OFPortDescPropBsnGenerationIdVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 20;

        private final static U64 DEFAULT_GENERATION_ID = U64.ZERO;

    // OF message fields
    private final U64 generationId;
//
    // Immutable default instance
    final static OFPortDescPropBsnGenerationIdVer15 DEFAULT = new OFPortDescPropBsnGenerationIdVer15(
        DEFAULT_GENERATION_ID
    );

    // package private constructor - used by readers, builders, and factory
    OFPortDescPropBsnGenerationIdVer15(U64 generationId) {
        if(generationId == null) {
            throw new NullPointerException("OFPortDescPropBsnGenerationIdVer15: property generationId cannot be null");
        }
        this.generationId = generationId;
    }

    // Accessors for OF message fields
    @Override
    public long getExpType() {
        return 0x1L;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public U64 getGenerationId() {
        return generationId;
    }

    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFPortDescPropBsnGenerationId.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFPortDescPropBsnGenerationId.Builder {
        final OFPortDescPropBsnGenerationIdVer15 parentMessage;

        // OF message fields
        private boolean generationIdSet;
        private U64 generationId;

        BuilderWithParent(OFPortDescPropBsnGenerationIdVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getExpType() {
        return 0x1L;
    }

    @Override
    public OFPortDescPropBsnGenerationId.Builder setExpType(long expType) {
            throw new UnsupportedOperationException("Property expType is not writeable");
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public U64 getGenerationId() {
        return generationId;
    }

    @Override
    public OFPortDescPropBsnGenerationId.Builder setGenerationId(U64 generationId) {
        this.generationId = generationId;
        this.generationIdSet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFPortDescPropBsnGenerationId build() {
                U64 generationId = this.generationIdSet ? this.generationId : parentMessage.generationId;
                if(generationId == null)
                    throw new NullPointerException("Property generationId must not be null");

                //
                return new OFPortDescPropBsnGenerationIdVer15(
                    generationId
                );
        }

    }

    static class Builder implements OFPortDescPropBsnGenerationId.Builder {
        // OF message fields
        private boolean generationIdSet;
        private U64 generationId;

    @Override
    public long getExpType() {
        return 0x1L;
    }

    @Override
    public OFPortDescPropBsnGenerationId.Builder setExpType(long expType) {
            throw new UnsupportedOperationException("Property expType is not writeable");
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public U64 getGenerationId() {
        return generationId;
    }

    @Override
    public OFPortDescPropBsnGenerationId.Builder setGenerationId(U64 generationId) {
        this.generationId = generationId;
        this.generationIdSet = true;
        return this;
    }
    @Override
    public int getType() {
        return 0xffff;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFPortDescPropBsnGenerationId build() {
            U64 generationId = this.generationIdSet ? this.generationId : DEFAULT_GENERATION_ID;
            if(generationId == null)
                throw new NullPointerException("Property generationId must not be null");


            return new OFPortDescPropBsnGenerationIdVer15(
                    generationId
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFPortDescPropBsnGenerationId> {
        @Override
        public OFPortDescPropBsnGenerationId readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0xffff
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=0xffff(0xffff), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 20)
                throw new OFParseError("Wrong length: Expected=20(20), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            // fixed value property expType == 0x1L
            int expType = bb.readInt();
            if(expType != 0x1)
                throw new OFParseError("Wrong expType: Expected=0x1L(0x1L), got="+expType);
            U64 generationId = U64.ofRaw(bb.readLong());

            OFPortDescPropBsnGenerationIdVer15 portDescPropBsnGenerationIdVer15 = new OFPortDescPropBsnGenerationIdVer15(
                    generationId
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", portDescPropBsnGenerationIdVer15);
            return portDescPropBsnGenerationIdVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFPortDescPropBsnGenerationIdVer15Funnel FUNNEL = new OFPortDescPropBsnGenerationIdVer15Funnel();
    static class OFPortDescPropBsnGenerationIdVer15Funnel implements Funnel<OFPortDescPropBsnGenerationIdVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFPortDescPropBsnGenerationIdVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0xffff
            sink.putShort((short) 0xffff);
            // fixed value property length = 20
            sink.putShort((short) 0x14);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property expType = 0x1L
            sink.putInt(0x1);
            message.generationId.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFPortDescPropBsnGenerationIdVer15> {
        @Override
        public void write(ByteBuf bb, OFPortDescPropBsnGenerationIdVer15 message) {
            // fixed value property type = 0xffff
            bb.writeShort((short) 0xffff);
            // fixed value property length = 20
            bb.writeShort((short) 0x14);
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property expType = 0x1L
            bb.writeInt(0x1);
            bb.writeLong(message.generationId.getValue());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFPortDescPropBsnGenerationIdVer15(");
        b.append("generationId=").append(generationId);
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
        OFPortDescPropBsnGenerationIdVer15 other = (OFPortDescPropBsnGenerationIdVer15) obj;

        if (generationId == null) {
            if (other.generationId != null)
                return false;
        } else if (!generationId.equals(other.generationId))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((generationId == null) ? 0 : generationId.hashCode());
        return result;
    }

}
