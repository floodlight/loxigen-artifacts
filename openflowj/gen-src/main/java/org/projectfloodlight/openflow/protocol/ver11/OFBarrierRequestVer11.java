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
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBarrierRequestVer11 implements OFBarrierRequest {
    private static final Logger logger = LoggerFactory.getLogger(OFBarrierRequestVer11.class);
    // version: 1.1
    final static byte WIRE_VERSION = 2;
    final static int LENGTH = 8;

        private final static long DEFAULT_XID = 0x0L;

    // OF message fields
    private final long xid;
//
    // Immutable default instance
    final static OFBarrierRequestVer11 DEFAULT = new OFBarrierRequestVer11(
        DEFAULT_XID
    );

    // package private constructor - used by readers, builders, and factory
    OFBarrierRequestVer11(long xid) {
        this.xid = xid;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public OFType getType() {
        return OFType.BARRIER_REQUEST;
    }

    @Override
    public long getXid() {
        return xid;
    }



    public OFBarrierRequest.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBarrierRequest.Builder {
        final OFBarrierRequestVer11 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;

        BuilderWithParent(OFBarrierRequestVer11 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public OFType getType() {
        return OFType.BARRIER_REQUEST;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBarrierRequest.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }


        @Override
        public OFBarrierRequest build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;

                //
                return new OFBarrierRequestVer11(
                    xid
                );
        }

    }

    static class Builder implements OFBarrierRequest.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public OFType getType() {
        return OFType.BARRIER_REQUEST;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBarrierRequest.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
//
        @Override
        public OFBarrierRequest build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;


            return new OFBarrierRequestVer11(
                    xid
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFBarrierRequest> {
        @Override
        public OFBarrierRequest readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 2
            byte version = bb.readByte();
            if(version != (byte) 0x2)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_11(2), got="+version);
            // fixed value property type == 20
            byte type = bb.readByte();
            if(type != (byte) 0x14)
                throw new OFParseError("Wrong type: Expected=OFType.BARRIER_REQUEST(20), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 8)
                throw new OFParseError("Wrong length: Expected=8(8), got="+length);
            //
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());

            OFBarrierRequestVer11 barrierRequestVer11 = new OFBarrierRequestVer11(
                    xid
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", barrierRequestVer11);
            return barrierRequestVer11;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBarrierRequestVer11Funnel FUNNEL = new OFBarrierRequestVer11Funnel();
    static class OFBarrierRequestVer11Funnel implements Funnel<OFBarrierRequestVer11> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBarrierRequestVer11 message, PrimitiveSink sink) {
            // fixed value property version = 2
            sink.putByte((byte) 0x2);
            // fixed value property type = 20
            sink.putByte((byte) 0x14);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            sink.putLong(message.xid);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBarrierRequestVer11> {
        @Override
        public void write(ByteBuf bb, OFBarrierRequestVer11 message) {
            // fixed value property version = 2
            bb.writeByte((byte) 0x2);
            // fixed value property type = 20
            bb.writeByte((byte) 0x14);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            bb.writeInt(U32.t(message.xid));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBarrierRequestVer11(");
        b.append("xid=").append(xid);
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
        OFBarrierRequestVer11 other = (OFBarrierRequestVer11) obj;

        if( xid != other.xid)
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
        OFBarrierRequestVer11 other = (OFBarrierRequestVer11) obj;

        // ignore XID
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        return result;
    }

}
