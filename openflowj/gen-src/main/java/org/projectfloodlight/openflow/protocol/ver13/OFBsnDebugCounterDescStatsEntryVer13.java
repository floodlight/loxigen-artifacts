// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnDebugCounterDescStatsEntryVer13 implements OFBsnDebugCounterDescStatsEntry {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnDebugCounterDescStatsEntryVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 328;

        private final static U64 DEFAULT_COUNTER_ID = U64.ZERO;
        private final static String DEFAULT_NAME = "";
        private final static String DEFAULT_DESCRIPTION = "";

    // OF message fields
    private final U64 counterId;
    private final String name;
    private final String description;
//
    // Immutable default instance
    final static OFBsnDebugCounterDescStatsEntryVer13 DEFAULT = new OFBsnDebugCounterDescStatsEntryVer13(
        DEFAULT_COUNTER_ID, DEFAULT_NAME, DEFAULT_DESCRIPTION
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnDebugCounterDescStatsEntryVer13(U64 counterId, String name, String description) {
        if(counterId == null) {
            throw new NullPointerException("OFBsnDebugCounterDescStatsEntryVer13: property counterId cannot be null");
        }
        if(name == null) {
            throw new NullPointerException("OFBsnDebugCounterDescStatsEntryVer13: property name cannot be null");
        }
        if(description == null) {
            throw new NullPointerException("OFBsnDebugCounterDescStatsEntryVer13: property description cannot be null");
        }
        this.counterId = counterId;
        this.name = name;
        this.description = description;
    }

    // Accessors for OF message fields
    @Override
    public U64 getCounterId() {
        return counterId;
    }

    @Override
    public String getDescription() {
        return description;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFBsnDebugCounterDescStatsEntry.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnDebugCounterDescStatsEntry.Builder {
        final OFBsnDebugCounterDescStatsEntryVer13 parentMessage;

        // OF message fields
        private boolean counterIdSet;
        private U64 counterId;
        private boolean nameSet;
        private String name;
        private boolean descriptionSet;
        private String description;

        BuilderWithParent(OFBsnDebugCounterDescStatsEntryVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public U64 getCounterId() {
        return counterId;
    }

    @Override
    public OFBsnDebugCounterDescStatsEntry.Builder setCounterId(U64 counterId) {
        this.counterId = counterId;
        this.counterIdSet = true;
        return this;
    }
    @Override
    public String getDescription() {
        return description;
    }

    @Override
    public OFBsnDebugCounterDescStatsEntry.Builder setDescription(String description) {
        this.description = description;
        this.descriptionSet = true;
        return this;
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFBsnDebugCounterDescStatsEntry.Builder setName(String name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFBsnDebugCounterDescStatsEntry build() {
                U64 counterId = this.counterIdSet ? this.counterId : parentMessage.counterId;
                if(counterId == null)
                    throw new NullPointerException("Property counterId must not be null");
                String name = this.nameSet ? this.name : parentMessage.name;
                if(name == null)
                    throw new NullPointerException("Property name must not be null");
                String description = this.descriptionSet ? this.description : parentMessage.description;
                if(description == null)
                    throw new NullPointerException("Property description must not be null");

                //
                return new OFBsnDebugCounterDescStatsEntryVer13(
                    counterId,
                    name,
                    description
                );
        }

    }

    static class Builder implements OFBsnDebugCounterDescStatsEntry.Builder {
        // OF message fields
        private boolean counterIdSet;
        private U64 counterId;
        private boolean nameSet;
        private String name;
        private boolean descriptionSet;
        private String description;

    @Override
    public U64 getCounterId() {
        return counterId;
    }

    @Override
    public OFBsnDebugCounterDescStatsEntry.Builder setCounterId(U64 counterId) {
        this.counterId = counterId;
        this.counterIdSet = true;
        return this;
    }
    @Override
    public String getDescription() {
        return description;
    }

    @Override
    public OFBsnDebugCounterDescStatsEntry.Builder setDescription(String description) {
        this.description = description;
        this.descriptionSet = true;
        return this;
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFBsnDebugCounterDescStatsEntry.Builder setName(String name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFBsnDebugCounterDescStatsEntry build() {
            U64 counterId = this.counterIdSet ? this.counterId : DEFAULT_COUNTER_ID;
            if(counterId == null)
                throw new NullPointerException("Property counterId must not be null");
            String name = this.nameSet ? this.name : DEFAULT_NAME;
            if(name == null)
                throw new NullPointerException("Property name must not be null");
            String description = this.descriptionSet ? this.description : DEFAULT_DESCRIPTION;
            if(description == null)
                throw new NullPointerException("Property description must not be null");


            return new OFBsnDebugCounterDescStatsEntryVer13(
                    counterId,
                    name,
                    description
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnDebugCounterDescStatsEntry> {
        @Override
        public OFBsnDebugCounterDescStatsEntry readFrom(ByteBuf bb) throws OFParseError {
            U64 counterId = U64.ofRaw(bb.readLong());
            String name = ChannelUtils.readFixedLengthString(bb, 64);
            String description = ChannelUtils.readFixedLengthString(bb, 256);

            OFBsnDebugCounterDescStatsEntryVer13 bsnDebugCounterDescStatsEntryVer13 = new OFBsnDebugCounterDescStatsEntryVer13(
                    counterId,
                      name,
                      description
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnDebugCounterDescStatsEntryVer13);
            return bsnDebugCounterDescStatsEntryVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnDebugCounterDescStatsEntryVer13Funnel FUNNEL = new OFBsnDebugCounterDescStatsEntryVer13Funnel();
    static class OFBsnDebugCounterDescStatsEntryVer13Funnel implements Funnel<OFBsnDebugCounterDescStatsEntryVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnDebugCounterDescStatsEntryVer13 message, PrimitiveSink sink) {
            message.counterId.putTo(sink);
            sink.putUnencodedChars(message.name);
            sink.putUnencodedChars(message.description);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnDebugCounterDescStatsEntryVer13> {
        @Override
        public void write(ByteBuf bb, OFBsnDebugCounterDescStatsEntryVer13 message) {
            bb.writeLong(message.counterId.getValue());
            ChannelUtils.writeFixedLengthString(bb, message.name, 64);
            ChannelUtils.writeFixedLengthString(bb, message.description, 256);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnDebugCounterDescStatsEntryVer13(");
        b.append("counterId=").append(counterId);
        b.append(", ");
        b.append("name=").append(name);
        b.append(", ");
        b.append("description=").append(description);
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
        OFBsnDebugCounterDescStatsEntryVer13 other = (OFBsnDebugCounterDescStatsEntryVer13) obj;

        if (counterId == null) {
            if (other.counterId != null)
                return false;
        } else if (!counterId.equals(other.counterId))
            return false;
        if (name == null) {
            if (other.name != null)
                return false;
        } else if (!name.equals(other.name))
            return false;
        if (description == null) {
            if (other.description != null)
                return false;
        } else if (!description.equals(other.description))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((counterId == null) ? 0 : counterId.hashCode());
        result = prime * result + ((name == null) ? 0 : name.hashCode());
        result = prime * result + ((description == null) ? 0 : description.hashCode());
        return result;
    }

}
